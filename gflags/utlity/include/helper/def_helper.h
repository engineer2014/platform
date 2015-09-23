#pragma once

struct UTLITY_EXT_CLASS tagCodeInfo
{
	string m_id;
	string m_code_type;
	string m_min_length;
	string m_max_length;
	string m_description;
};

struct UTLITY_EXT_CLASS tagSoftInfo
{
	string				     uu_soft_id;
	string				     uu_soft_key;
	string				     uu_soft_check_key;
	map<string, tagCodeInfo> uu_codemap;
	string				     rk_soft_id;
	string				     rk_soft_key;
	string				     rk_soft_check_key;
	map<string, tagCodeInfo> rk_codemap;
	string				     lz_soft_id;
	string				     lz_soft_key;
	string				     lz_soft_check_key;
	map<string, tagCodeInfo> lz_codemap;
};

struct UTLITY_EXT_CLASS tagPhoneInfo
{
	string				aima_author_id;
	map<string, string> aima_pidmap;
	string				yima_author_id;
	map<string, string> yima_pidmap;
	string				soma_author_id;
	map<string, string> soma_pidmap;
	string				kuaima_author_id;
	map<string, string> kuaima_pidmap;
};

struct UTLITY_EXT_CLASS tagIpChange
{
	string tag_ip;
	CTime  tag_time;
};

typedef enum eMAIL_TYPE 
{
	eMAIL_TYPE_UN     = 0,
	eMAIL_TYPE_163    = 1,
	eMAIL_TYPE_126    = 2,
	eMAIL_TYPE_YEAH   = 3,
	eMAIL_TYPE_TOM	  = 4,
	eMAIL_TYPE_SOHU   = 5
}eMAIL_TYPE;