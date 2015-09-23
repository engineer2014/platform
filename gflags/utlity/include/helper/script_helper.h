#pragma once

class CScriptObject;

class UTLITY_EXT_CLASS script_helper
{
public:
	script_helper(void);
	~script_helper(void);
public:
	bool   load_script(string str_file);
	bool   run_procedure(string str_funcname, vector<string> vec_params, string& str_result);
	string error_info();
private:
	CScriptObject* m_scriptobj;
	string		   m_error;
};