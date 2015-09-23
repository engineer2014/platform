#pragma once

class UTLITY_EXT_CLASS txt_helper
{
public:
	txt_helper(void);
	~txt_helper(void);

public:
	static string read_file(string strfile);
	static void   save_file(string str_file, string str_content, int app = ios::app);
	static bool   read_jpg(string str_file, char*& buffer, int& size);
	static bool   save_jpg(string str_file, const char* buffer, int size);
	static string cookie_value(string str_cookie_file, string str_cookie_name);
};
