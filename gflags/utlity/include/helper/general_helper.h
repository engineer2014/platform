#pragma once

UTLITY_EXT_CLASS long writer(void* data, int size, int nmemb, string& content);
UTLITY_EXT_CLASS long fwriter(void* data, int size, size_t nmemb, void* stream);
UTLITY_EXT_CLASS void init_locks(void);
UTLITY_EXT_CLASS void kill_locks(void);
UTLITY_EXT_CLASS string  cstring_string(CString str);
UTLITY_EXT_CLASS CString string_cstring(string str);
UTLITY_EXT_CLASS string  total_milliseconds();
UTLITY_EXT_CLASS __int64 total_milliseconds_int();
UTLITY_EXT_CLASS char* info(string str_msg);
UTLITY_EXT_CLASS DWORD start_update(HWND hwnd, string str_file, string str_command);