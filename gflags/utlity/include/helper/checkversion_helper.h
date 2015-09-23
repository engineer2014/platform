#pragma once

// 版本检查
class UTLITY_EXT_CLASS checkversion_helper
{
public:
	checkversion_helper(void);
	~checkversion_helper(void);

public:
	// 字符串转成数值版本
	static int calc_version(string str_ver);

public:
	// 检查新版本，返回true时有新版本
	bool   check_new(string str_appname, string str_cur_ver, string str_url);

	// 软件开关
	bool   check_on(string str_appname, string str_url, bool switchon = true);

	// 新版本号
	string app_last_ver();

	// 软件开关
	bool   app_switchon();

	// 强制使用新版本
	bool   app_force();

	// 程序名称
	string app_name();

	// 新版本下载地址
	string app_address();

	// 软件提示
	string app_tips(bool butf8 = true);

private:
	bool   get_version_info();

private:
	string m_str_url;      // 更新地址
	string m_appname;      // 程序名称
	string m_cur_ver;      // 当前版本
	string m_app_ver;      // 服务器版本
	bool   m_app_switchon; // 开关
	bool   m_app_force;    // 强制使用最新版本
	string m_app_address;  // 新版本地址
	string m_app_tips;     // 软件提示
};
