#pragma once
#include "def_helper.h"

class UTLITY_EXT_CLASS param_helper
{
public:
	param_helper(void);
	virtual ~param_helper(void);

public:
	virtual void init_param(HWND hwnd, int msg = -1);
	virtual bool load_param();
	virtual bool save_param();
	virtual void clear();

private:
	void   init_picture_dama(string str_file);
	void   init_phone_dama(string str_file);

public:
	void   dama_setting();
	void   phonedama_setting();
	void   changeip_setting();

public:
	HWND   get_hwnd();
	int    get_msgno();
	void   set_dama_type(int ntype);
	int    get_dama_type();
	void   set_dama_user(string str_user);
	string get_dama_user();
	void   set_dama_pwd(string str_pwd);
	string get_dama_pwd();
	void   set_dama_error_try(int ntrys);
	int    get_dama_error_try();
	void   set_soft_info(tagSoftInfo tagInfo);
	string get_soft_id();
	string get_soft_key();
	string get_soft_check_key();
	string get_codetype(string str_key);
	string get_minlength(string str_key);
	string get_maxlength(string str_key);
	void   set_phonedama_type(int ntype);
	int    get_phonedama_type();
	void   set_phonedama_user(string str_user);
	string get_phonedama_user();
	void   set_phonedama_pwd(string str_pwd);
	string get_phonedama_pwd();
	void   set_phone_info(tagPhoneInfo phongInfo);
	string get_author_id();
	string get_pid(string str_key);
	void   set_dial_type(int ntype);
	int    get_dial_type();
	void   set_dial_name(string str_name);
	string get_dial_name();
	void   set_dial_pwd(string str_pwd);
	string get_dial_pwd();
	void   set_dial_span(int nspan);
	int    get_dial_span();
	void   set_dial_times(int ntimes);
	int    get_dial_times();
	void   set_discon_wait(int nwait);
	int	   get_discon_wait();
	void   set_iptime(int ntime);
	int    get_iptime();
	void   set_route_type(string str_route_type);
	string get_route_type();
	void   set_route_address(string str_route_address);
	string get_route_address();
	void   set_stop_change(bool bstop);
	bool   get_stop_change();
	void   set_ie_proxy(int ntype);
	int    get_ie_proxy();
	void   set_time_out(int nseconds);
	int    get_time_out();
	void   set_span(int nspan);
	int	   get_span();

private:
	HWND           m_hwnd;
	int            m_msgno;
	int            m_dama_type;
	string         m_uu_user;
	string         m_uu_pwd;
	int			   m_dama_error_try;
	tagSoftInfo    m_soft_info;
	int			   m_phonedama_type;
	string         m_aima_user;
	string         m_aima_pwd;
	tagPhoneInfo   m_phone_info;
	int            m_dial_type;
	string         m_dialname;
	string         m_dialpwd;
	int            m_dial_span;
	int            m_dial_times;
	int			   m_discon_wait;
	int            m_iptime;
	string         m_route_type;
	string         m_route_address;
	bool           m_stop_change;
	int			   m_ie_proxy;
	int		       m_time_out;
	int			   m_span;
};