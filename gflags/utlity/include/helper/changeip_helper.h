#pragma once

class UTLITY_EXT_CLASS changeip_helper
{
public:
	changeip_helper(void);
	~changeip_helper(void);

public:
	enum
	{
		eUSER_PWD_ERROR,
		eCONFIG_ERROR,
		eHAVE_CONNECT,
		eNO_CONNECT,
		eCONNECT_CREATED_OK,
		eCONNECT_CREATED_FAILD,
		eCONNECT_CONNECTING,
		eCONNECT_SUCCED,
		eCONNECT_FAILD,
		eCONNECT_CLOSING,
		eCONNECT_CLOSED,
		eNETTYPE_UNKNOWN,
		eNETTYPE_MODEM,
		eNETTYPE_LAN,
		eNETTYPE_PROXY
	};

public:
	int changeip(param_helper* param, string& str_error);
public:
	static string network_ip();
	static int    network_type();
public:
	int    dial_changeip(string str_user, string str_pwd, int wait_time = 0);
	int    dial_connect(string str_user, string str_pwd);
	int    dial_close();
public:
	int    route_changeip(string str_user, string str_pwd, string str_adress, string str_type_file, int wait_time = 0);
	int    route_connect();
	int    route_disconnect();

public:
	string get_connect_ip();

private:
	int    ras_create_ppoe(string str_ppoe_name = "asNetWork");
	int    ras_connect(string str_user, string str_pwd, string str_ppoe_name);
	int    ras_enum_connect(string& str_ppoe_name);
	int    ras_connect_state();
	int    ras_close();
private:
	bool   read_config(string str_config);
private:
	bool   get(string str_url, string str_data, string str_ref, string str_cookie_file, string& str_response);
private:
	string tp842n_encodepwd(string str_srcpwd);
	string tp842n_securityEncode(string input1, string input2, string input3);
	string tp842n_orgAuthPwd(string pwd);

private:
	string m_connect_ip;

private:
	string m_str_user;
	string m_str_pwd;
	string m_route_address;
	string m_discon_url;
	string m_discon_post;
	string m_discon_src_url;
	string m_discon_src_regex;
	string m_con_url;
	string m_con_post;
	string m_con_src_url;
	string m_con_src_regex;
	string m_header_validate;
	string m_cookie_validate;
	string m_url_code;
	string m_must_visit_url;
	string m_must_visit_regex;
	string m_must_visit_regex2;
	string m_must_visit_dynamic;
	string m_must_visit_dynamic2;
	string m_must_visit_url_cookie;
	string m_webform_login_url;
	string m_webform_login_data;
	string m_webform_login_conform_url;
};