#pragma once
#include <process.h>

typedef unsigned (__stdcall *PTHREAD_START) (void *);
#define chBEGINTHREADEX(psa, cbStack, pfnStartAddr, \
	pvParam, fdwCreate, pdwThreadId)\
	((HANDLE)_beginthreadex( \
	(void *)        (psa),\
	(unsigned)      (cbStack),\
	(PTHREAD_START) (pfnStartAddr),\
	(void *)        (pvParam),\
	(unsigned)      (fdwCreate),\
	(unsigned *)    (pdwThreadId)))
template<class T, class P>
class thread_helper
{
public:
	typedef void (T::*ThreadFunc)( P );
	thread_helper();
	virtual ~thread_helper();

public:
	/// Run - Start the Thread and run the method
	// pClass->(*pfFunc), passing p as an argument.
	// Returns true if the thread was created successfully, false otherwise
	bool Run( T* pClass, ThreadFunc pfFunc, P p, DWORD fdwCreate);

	/// Suspend - Suspends the thread (if one is active)
	void Suspend();

	/// Resume - Resumes a previously suspended thread
	void Resume();

	/// Terminate - Terminates the thread (if one is active).
	// Prefer another means of exiting the thread, as
	// calling Terminate() does not allow the thread to free
	// any resources it may hold
	void Terminate(DWORD dwExitCode);

	/// SetThreadPriority - Set thread priority
	void SetThreadPriority(int nPriority);

	/// IsThreadActive - Called in the context of another
	// (external) thread to test whether the thread is
	// currently running
	bool IsThreadActive() const;

	/// GetThreadId - Called in the context of another
	// (external) thread to get the thread ID.
	DWORD GetThreadId() const;

	/// GetThreadHandle - Called in the context of another
	// (external) thread to get the thread Handle.
	HANDLE GetThreadHandle() const;

	/// 关闭线程句柄
	void CloseThreadHandle();

protected:
	/// Static Thread Proc - The ThreadProc called by the
	// _beginthreadex() function of C Run-time library .
	// The parameter is a pointer to the thread instance
	// that is being started.
	static DWORD WINAPI StartThread(void* pParam);

private:
	thread_helper(const thread_helper&);
	thread_helper& operator=(const thread_helper &);

protected:
	HANDLE      m_hThread; ///< Handle of the created Thread

	DWORD       m_threadID;///< ID of the created thread

	T*			m_pInstance;///< ThreadFunc invoketion members
	ThreadFunc	m_pfFunc;   ///< function
	P			m_param;    ///< param
};

// 实现
template<class T, class P>
thread_helper<T, P>::thread_helper()
: m_hThread(NULL)
, m_threadID((DWORD)-1)
, m_pInstance(NULL)
, m_pfFunc(NULL)
{

}

template<class T, class P>
thread_helper<T, P>::~thread_helper()
{
	if (IsThreadActive())
		Terminate(0);

	if (m_hThread)
	{
		::CloseHandle(m_hThread);
		m_hThread = NULL;
	}
}

template<class T, class P>
bool thread_helper<T, P>::Run(
							  T* pClass,
							  ThreadFunc pfFunc,
							  P param,
							  DWORD fdwCreate
							  )
{
	// Store the values in this class instance so
	// the static StartThread() function can call
	// the appropriate method on the object
	if (pClass == NULL || pfFunc == NULL)
	{
		return false;
	}

	m_pInstance = pClass;
	m_pfFunc = pfFunc;
	m_param = param;

	m_hThread = chBEGINTHREADEX(
		NULL,
		0,
		StartThread,
		this,
		fdwCreate,
		&m_threadID);

	return (m_hThread != NULL);
}

template<class T, class P>
void thread_helper<T, P>::Suspend()
{
	::SuspendThread(m_hThread);
}

template<class T, class P>
void thread_helper<T, P>::Resume()
{
	if (m_hThread)
	{
		int nResumeCount = ::ResumeThread( m_hThread );
		while (nResumeCount > 1)
		{
			nResumeCount = ::ResumeThread( m_hThread );
		}
	}
}

template<class T, class P>
void thread_helper<T, P>::SetThreadPriority(int nPriority)
{
	if (m_hThread)
	{
		::SetThreadPriority(m_hThread, nPriority);
	}
}

template<class T, class P>
void thread_helper<T, P>::Terminate(DWORD dwExitCode)
{
	if (m_hThread)
	{
		::TerminateThread( m_hThread, dwExitCode );
		::CloseHandle( m_hThread );
		m_hThread = NULL;
	}
}

template<class T, class P>
bool thread_helper<T, P>::IsThreadActive() const
{
	return ((m_hThread != NULL)&&(::WaitForSingleObject(m_hThread, 0) != WAIT_OBJECT_0));
}

template<class T, class P>
DWORD thread_helper<T, P>::GetThreadId() const
{
	return m_threadID;
}

template<class T, class P>
HANDLE thread_helper<T, P>::GetThreadHandle() const
{
	return m_hThread;
}

template<class T, class P>
void thread_helper<T, P>::CloseThreadHandle()
{
	if (m_hThread)
	{
		::CloseHandle(m_hThread);
		m_hThread = NULL;
	}	
}

template<class T, class P>
DWORD WINAPI thread_helper<T, P>::StartThread(void* pParam)
{
	thread_helper* pInstance = reinterpret_cast<thread_helper*>(pParam);

	if (!pInstance)
		return (DWORD)-1;

	// Get the invoketion variables so we don't have to
	// use even more funky syntax
	T* pClassInstance = pInstance->m_pInstance;
	ThreadFunc pfFunc = pInstance->m_pfFunc;
	P param = pInstance->m_param;

	// We have a valid instance of the Thread class, use
	// the thread's stored parameters to call the client
	// (worker) function.  This will continue to run in
	// the context of this (seperate) thread until finished
	((*pClassInstance).*pfFunc)(param);

	return 0;
}