#pragma once

class UTLITY_EXT_CLASS string_helper
{
public:
	string_helper(void);
	~string_helper(void);

public:
	static bool			  to_bool(string value);
	static int			  to_int(string value);
	static __int64		  to_int64(string value);
	static unsigned long  to_dword(string value);
	static float		  to_float(string value);
	static double		  to_double(string value);
	static wstring		  to_wstring(string value);
	static CTime          to_ctime(string value);

public:
	static string		  from_bool(bool value);
	static string		  from_int(int value);
	static string		  from_int64(__int64 value);
	static string		  from_dword(unsigned long value);
	static string		  from_float(float value);
	static string		  from_double(double value);
	static string		  from_wstring(wstring value);
	static string		  from_ctime(CTime t);

public:
	static bool			  wto_bool(wstring value);
	static int			  wto_int(wstring value);
	static unsigned long  wto_dword(wstring value);
	static float	      wto_float(wstring value);
	static double	      wto_double(wstring value);

public:
	static wstring		  wfrom_bool(bool value);
	static wstring	      wfrom_int(int value);
	static wstring		  wfrom_dword(unsigned long value);
	static wstring		  wfrom_float(float value);
	static wstring		  wfrom_double(double value);

public:
	static vector<string> split(const string& str, const string& delimiters);
	static double		  similar_degree(const string& sa, const string& sb);
	static bool		      replace(string& str_source, string str_search, string str_replace, bool bonce = false);

public:
	static string		  mb_utf8(const string& str_mb);
	static string		  utf8_mb(const string& str_utf8);
	static string		  url_encode(const string& str_source);
	static string		  url_decode(const string& str_source);
	static string		  uri_encode(const string& str_source);
	static string         uricomponent_encode(const string& str_source);
	static string         url_encode(const string& str_source, bool bconvert_utf8);
	static string		  base64_encode(const string& src); 
	static string		  base64_decode(const string& src);
	static string         md5_encode(const string& src);
	static bool			  bytes_md5(string& str_md5, const BYTE* lpBuffer, DWORD lpNumberOfBytes);
	static string		  unicode_chinese(const string& src);
	static string		  chinese_unicode(const string& src);

private:
	static bool			  is_base64(unsigned char c);
	static char			  dec_hex(short int n);
	static short int	  hex_dec(char c);
};
