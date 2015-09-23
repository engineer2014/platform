#pragma once

class UTLITY_EXT_CLASS debug_helper
{
private:
	debug_helper(void);
	virtual ~debug_helper(void);
public:
	static debug_helper* getInstance();
	static void destoryInstance();
public:
	void init(HWND hwnd, UINT nmsg, long edit_id);
public:
	void postmessage(const char* format, ...);
	void postmessage(UINT msg, const char* format, ...);
	void print(const char* format, ...);
	void print(long nedit_id, const char* format, ...);

public:
	static string parse(const char* format, ...);
public:
	static void   trace(char* fileName, int line, const char* format, ...);
public:
	static string cur_time();
public:
	void init_log(string str_folder = "",  string str_specname = "", bool bcurdir = true);
	void write_log(string str_log, bool boverwrite = false);
public:
	void   start();
	double stop(bool start_again = false);
	double elapsed_time();
public:
	static void init_crash();
	static long crash_handler(EXCEPTION_POINTERS* pException);
	static void create_dumpfile(LPCSTR lpstrDumpFilePathName, EXCEPTION_POINTERS* pException);
	
private:
	static debug_helper* m_debuger;
	HWND m_hwnd;
	UINT m_msg;
	long m_edit_id;
	string m_str_logfilename;
	LARGE_INTEGER m_start_time;
	LARGE_INTEGER m_stop_time;
};
