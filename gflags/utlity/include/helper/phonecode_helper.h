#pragma once
#include "param_helper.h"

class UTLITY_EXT_CLASS phonecode_helper
{
public:
	phonecode_helper(void);
	~phonecode_helper(void);

public:
	enum
	{
		eHanddama,
		eAiMadama,
		eYiMadama,
		eSoMadama,
		eKuaiMadama,
		eOK,
		eCancle,
		eNotReceived,
		eRetry,
		eFailed
	};

public:
	int     v_init(param_helper* param);
	int     v_receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format);
	int     v_recognize_code(string& str_vcode, string str_mobile, string str_exp, int timeout = 100);
	int     v_query_score(string& str_score);
	string  v_register_address();
	int     v_cancle_mobilenum(string str_pid, string str_mobile);
	int     v_report_error(string str_pid, string str_mobile);
public:
	int     init(string user, string pwd, string str_author_id, HWND hwnd, int type);
	int     receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format, string& str_error);
	int     recognize_code(string& str_vcode, string str_mobile, string str_exp, string& str_error, int timeout = 100);
	int     query_score(string& str_score, string& str_error);
	string  register_address();
	int     cancle_mobilenum(string str_pid, string str_mobile, string& str_error);
	int     report_error(string str_pid, string str_mobile, string& str_error);	
public:
	static int hand_code(string& str_result, HWND parent, string str_mobile, bool binput = true);
public:
	int     aima_init(string user, string pwd, string str_author_id);
	int     aima_receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format, string& str_error);
	int     aima_recognize_code(string& str_vcode, string str_mobile, string str_exp, string& str_error);
	int     aima_query_score(string& str_score, string& str_error);
	string  aima_register_address();
	int     aima_cancle_mobilenum(string str_pid, string str_mobile, string& str_error);
	int     aima_report_error(string str_pid, string str_mobile, string& str_error);

private:
	int     aima_Login(string str_user, string str_pwd, string& str_error);
	int     aima_getUserInfos(string str_user, string& str_error);
	int     aima_getMobilenum(string str_user, string str_pid, string str_mobile, string str_size, string& str_error);
	int     aima_getVcodeAndReleaseMobile(string str_user, string str_author_id, string str_mobile, string& str_error);
	int     aima_getVcodeAndHoldMobilenum(string str_user, string str_author_id, string str_mobile, string str_next_pid, string& str_error);
	int     aima_addIgnoreList(string str_user, string str_pid, string str_mobile, string& str_error);
	int     aima_cancelRecv(string str_user, string str_pid, string str_mobile, string& str_error);
	int     aima_cancelAllRecv(string& str_error);
	int     aima_sendSms(string str_user, string str_pid, string str_mobile, string str_content, string& str_error);
	int     aima_getSmsStatus(string str_user, string str_pid, string str_mobile, string& str_error);
	int     aima_getRecvingInfo(string str_user, string str_pid, string& str_error);
public:
	int     yima_init(string user, string pwd, string str_author_id);
	int     yima_receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format, string& str_error);
	int     yima_recognize_code(string& str_vcode, string str_mobile, string str_exp, string& str_error);
	int     yima_query_score(string& str_score, string& str_error);
	string  yima_register_address();
	int     yima_cancle_mobilenum(string str_pid, string str_mobile, string& str_error);
	int     yima_report_error(string str_pid, string str_mobile, string& str_error);
private:
	int     yima_Login(string str_user, string str_pwd, string& str_error);
	int     yima_getUserInfos(string str_user, string& str_error);
	int     yima_getMobilenum(string str_user, string str_pid, string str_mobile, string str_size, string& str_error);
	int     yima_getVcodeAndReleaseMobile(string str_pid, string str_author_id, string str_mobile, string& str_error);
	int     yima_getVcodeAndHoldMobilenum(string str_user, string str_author_id, string str_mobile, string str_next_pid, string& str_error);
	int     yima_addIgnoreList(string str_user, string str_pid, string str_mobile, string& str_error);
	int     yima_cancelRecv(string str_user, string str_pid, string str_mobile, string& str_error);
	int     yima_cancelAllRecv(string& str_error);
	int     yima_sendSms(string str_user, string str_pid, string str_mobile, string str_content, string& str_error);
	int     yima_getSmsStatus(string str_user, string str_pid, string str_mobile, string& str_error);
	int     yima_getRecvingInfo(string str_user, string str_pid, string& str_error);
private:
	bool    parse_yima(string str_src, vector<string>& vec_content);
public:
	int     soma_init(string user, string pwd, string str_author_id);
	int     soma_receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format, string& str_error);
	int     soma_recognize_code(string& str_vcode, string str_mobile, string str_exp, string& str_error);
	int     soma_query_score(string& str_score, string& str_error);
	string  soma_register_address();
	int     soma_cancle_mobilenum(string str_pid, string str_mobile, string& str_error);
	int     soma_report_error(string str_pid, string str_mobile, string& str_error);

private:
	int     soma_Login(string& str_error);
	int     soma_getUserInfos(string& str_error);
	int     soma_getMobilenum(string str_pid, string str_mobile_format/*&pr=&cy=&cr=*/, string str_size, string& str_error);
	int     soma_getVcodeAndReleaseMobile(string str_pid, string str_mobile, string& str_error);
	int     soma_addIgnoreList(string str_pid, string str_mobile, string& str_error);
	int     soma_cancelRecv(string str_pid, string str_mobile, string& str_error);
	int     soma_sendSms(string str_pid, string src_mobile, string des_mobile, string str_content, string& str_error);
	int     soma_getStatus(string str_pid, string str_mobile, string& str_error);

private:
	bool    parse_soma(string str_src);
public:
	int     kuaima_init(string user, string pwd, string str_author_id);
	int     kuaima_receive_mobilenum(string& str_mobile, string str_pid, string str_mobile_format, string& str_error);
	int     kuaima_recognize_code(string& str_vcode, string str_mobile, string str_exp, string& str_error);
	int     kuaima_query_score(string& str_score, string& str_error);
	string  kuaima_register_address();
	int     kuaima_cancle_mobilenum(string str_pid, string str_mobile, string& str_error);
	int     kuaima_report_error(string str_pid, string str_mobile, string& str_error);
	int     kuaima_exit(string& str_error);
private:
	int     kuaima_Login(string& str_error);
	int     kuaima_getUserInfos(string& str_error);
	int     kuaima_getMobilenum(string str_pid, string str_mobile_format/*&pr=&cy=&cr=*/, string str_size, string& str_error);
	int     kuaima_getVcodeAndReleaseMobile(string str_pid, string str_mobile, string& str_error);
	int     kuaima_addIgnoreList(string str_pid, string str_mobile, string& str_error);
	int     kuaima_cancelRecv(string str_pid, string str_mobile, string& str_error);
	int     kuaima_sendSms(string str_pid, string src_mobile, string des_mobile, string str_content, string& str_error);
	int     kuaima_getStatus(string str_pid, string str_mobile, string& str_error);
	int     kuaima_userExit(string& str_error);
private:
	bool    parse_kuaima(string str_src);
private:
	string  get_cookie_file();
private:
	HWND   m_hwnd;
	int    m_msgno;
	int	   m_dama_type;
	string m_user;
	string m_pwd;
	string m_user_token;
	string m_author_id;
	string m_pid;
};
