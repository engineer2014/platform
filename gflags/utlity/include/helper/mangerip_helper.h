#pragma once
#include "def_helper.h"
#include "param_helper.h"

class UTLITY_EXT_CLASS mangerip_helper
{
public:
	mangerip_helper();
	~mangerip_helper(void);
public:
	enum
	{
		eChangeNo,
		eChangeForce,
		eChangeForceLock,
		eChangeTimer,
		eChangeTimerLock
	};
public:
	void   init(param_helper* param);
	void   start();
	void   smart_change(int ntype);
	bool   lock_list(vector<string>& vec_list);
private:
	string type_change(int ntype);
	bool   is_change(int ntype);
	void   add_ip(string str_ip);
	bool   repeat_ip(string str_ip);

private:
	param_helper*       m_param;
	CTime               m_last_time;
	vector<tagIpChange> m_vec_ip;
};