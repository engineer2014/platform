#pragma once

// �汾���
class UTLITY_EXT_CLASS checkversion_helper
{
public:
	checkversion_helper(void);
	~checkversion_helper(void);

public:
	// �ַ���ת����ֵ�汾
	static int calc_version(string str_ver);

public:
	// ����°汾������trueʱ���°汾
	bool   check_new(string str_appname, string str_cur_ver, string str_url);

	// �������
	bool   check_on(string str_appname, string str_url, bool switchon = true);

	// �°汾��
	string app_last_ver();

	// �������
	bool   app_switchon();

	// ǿ��ʹ���°汾
	bool   app_force();

	// ��������
	string app_name();

	// �°汾���ص�ַ
	string app_address();

	// �����ʾ
	string app_tips(bool butf8 = true);

private:
	bool   get_version_info();

private:
	string m_str_url;      // ���µ�ַ
	string m_appname;      // ��������
	string m_cur_ver;      // ��ǰ�汾
	string m_app_ver;      // �������汾
	bool   m_app_switchon; // ����
	bool   m_app_force;    // ǿ��ʹ�����°汾
	string m_app_address;  // �°汾��ַ
	string m_app_tips;     // �����ʾ
};
