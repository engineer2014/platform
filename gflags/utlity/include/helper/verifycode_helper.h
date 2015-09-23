#pragma once
#include "param_helper.h"

class UTLITY_EXT_CLASS verifycode_helper
{
public:
	verifycode_helper(void);
	~verifycode_helper(void);

public:
	enum
	{
		eHanddama,
		eUUdama,
		eRKdama,
		eLZdama,
		eOk,
		eFailed,
		eCancle,
		eUserPwdError,
		eLimitSoftIP,
		eNoMoney,
		eCheckDllError,
	};

public:
	void    v_init(param_helper* param);
	int     v_recognize(string& str_result, string str_pic, string code_type, string min_len = "0", string max_len = "0");
	int     v_query_score(string& str_score);
	string  v_register_address();
	void    v_report_error();
public:
	void    init(string user, string pwd, string soft_id, string soft_key, string check_key, int ntype = eUUdama);
	int     recognize_code(string& str_result, string& code_id, string str_pic, string code_type, string min_len = "0", string max_len = "0");
	int     query_score(string& str_score);
	string  register_address();
	bool    report_error(string str_code_id, string& str_error);
public:
	static int hand_code(string& str_result, HWND parent, string str_pic);
public:
	void    uu_init(string user, string pwd, string soft_id, string soft_key, string check_key);
	int     uu_recognize_code(string& str_result, string& code_id, string str_pic, string code_type = "8001");
	int     uu_recognize_code(string& str_result, string& code_id, char* sz_pic, int nsize, string code_type);
	int     uu_query_score(string& str_score);
	string  uu_register_address();
	bool    uu_report_error(string str_code_id, string& str_error);
public:
	bool    check_dll(int soft_id, string soft_key, string uu_dllfile, string soft_check_key);
	int     login(string str_user, string str_pwd);
	void    set_soft_info(int soft_id, string soft_key);
	bool    recognize_code_path(string str_pic, int n_code_type, string& str_result);
	bool    recognize_code_byte(char* sz_pic, int nsize, int n_code_type, string& str_result);
	string  check_result(int soft_id, string check_key, int code, string result);
	int     get_score(string str_user, string str_pwd, string& str_error);
private:
	bool    CheckDll(int softid, const CString& strSoftKey, const CString& strDllPath, const CString& strCheckKey);
	CString CheckResult(const CString& strResult, int softid, int codeID, const CString& checkKey);
	int     Get_CRC(CString& csData, DWORD dwSize);
	void    MakeTable();
	CString GetFileCrc(const CString& strFileName);
	BOOL    GetBytesMD5(const BYTE* lpBuffer, DWORD lpNumberOfBytes, CString& strMD5);
	BOOL    GetFileMd5(CString strDllPath, CString& strFileMd5);
	CString MBCS2Utf8(const CString& szMBCS);
	BOOL    GetStringMD5(CString str, CString& strMD5);
public:
	void    rk_init(string user, string pwd, string soft_id, string soft_key, string check_key);
	int     rk_recognize_code(string& str_result, string& code_id, string str_pic, string code_type = "2040");
	int     rk_query_score(string& str_score);
	string  rk_register_address();
	bool    rk_report_error(string str_code_id, string& str_error);
public:
	void    lz_init(string user, string pwd, string soft_id, string soft_key, string check_key);
	int     lz_recognize_code(string& str_result, string& code_id, string str_pic, string code_type, string min_len = "0", string max_len = "0");
	int     lz_query_score(string& str_score);
	string  lz_register_address();
	bool    lz_report_error(string str_code_id, string& str_error);
private:
	bool    lz_upload(string& str_result, string& code_id, string str_pic, string code_type, string min_length, string max_length);
	bool    lz_error(string str_code_id);
	bool    lz_point(string& str_score);

private:
	HWND   m_hwnd;
	int    m_msgno;
	string m_code_id;
	int	   m_dama_type;
	string m_user;
	string m_pwd;
	string m_soft_id;
	string m_soft_key;
	string m_soft_check_key;
	string m_uu_dllfile;
};
