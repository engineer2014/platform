#pragma once

class UTLITY_EXT_CLASS criticalsection_helper
{
public:
	criticalsection_helper(void) {InitializeCriticalSection(&m_cs);}
	~criticalsection_helper(void) {DeleteCriticalSection(&m_cs);}
public:
	void enter(){EnterCriticalSection(&m_cs);}
	void leave(){LeaveCriticalSection(&m_cs);}
private:
	CRITICAL_SECTION m_cs;
};
