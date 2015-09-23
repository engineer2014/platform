#pragma once

class UTLITY_EXT_CLASS directory_helper
{
public:
	directory_helper(void);
	~directory_helper(void);

public:
	static bool   directory_valid(const string str_path);
	static bool   create_directory(const string str_path);
	static void   copy_directory(const string src_dir, const string des_dir);
	static bool   delete_directory(const string str_path);
	static void   rename_directory_file(const string str_path, const string str_ext, const string str_new_ext);
	static void   delete_directory_file(const string str_path, const string str_ext);
	static string get_current_directory();
	static string get_temp_directory();
	static string get_desktop_directory();
	static void   get_sub_directory(const string str_dir, vector<string>& v_list);
	static void   get_relative_sub_directory(const string str_dir, const string str_pre, vector<string>& v_list);
	static void   get_directory_file(const string str_dir, const string str_ext, vector<string>& v_list);
	static void   get_directory_file_ext(const string str_path, const string str_ext, vector<string>& v_list);
	static void   get_relative_directory_file_ext(const string str_path, const string str_pre, const string str_ext, vector<string>& v_list);
public:
	static bool   path_file_exist(const string str_file);
	static string get_file_path(const string str_file);
	static string get_file_name(const string str_file);
	static string get_file_name_without_ext(const string str_file);
	static string get_file_ext(const string str_file);
	static string get_file_without_ext(const string str_file);
	static void   rename_file(const string old_file, const string new_file);
	static bool   copy_file(const string str_src, const string str_desc, bool bfaillexist = true);
	static void   delete_file(const string str_file);
public:
	static bool file_path_dialog(string& str_file, const string str_filter, bool bopen = true);
	static bool directory_path_dialog(string& str_file, HWND hwnd);
};
