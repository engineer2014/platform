#pragma once

class UTLITY_EXT_CLASS curl_helper
{
public:
	curl_helper(void);
	~curl_helper(void);

public:
	enum eType
	{
		eGET,
		ePOST,
		ePUT,
		eDELETE,
		eUNKNOWN
	};

public:
	static bool get(string str_url, string str_cookie_file, string& str_response, int nhead = 0);
	static bool post(string str_url, string str_cookie_file, string str_post_data, string& str_response, int nhead = 0);

public:
	int     doRequest(string& str_error);

public:
	void    setType(eType type);
	eType   getType();
	void    setUrl(string strUrl);
	void    setUrl(const char* format, ...);
	string  getUrl();
	void    setHeader(string strHeader);
	void    setHeader(const char* format, ...);
	void    setHeader(const vector<string>& vecHeader);
	template<class T>
	bool    setOption(CURLoption option, T data);
	void    setRequestData(string strData);
	void    setRequestData(const char* format, ...);
	string& getRequestData();
	void    setMultipartData(string strName, string strContext);
	void    setMultipartData(string strName, string strFile, string strType, string strUrlFileName);
	void    setMultipartData(string strName, string strFileName, string strType, char* szBuffer, int bufferSize);
	void    setCookieFile(string strFile);
	void    setCookieFile(const char* format, ...);
	string  getCookieFile();

	void    setSSLFile(string strFile);
	string  getSSLFile();

	int     getResponseCode();
	string  getResponseHeader();
	string  getResponseContent();

private:
	CURL*          m_curl;
	curl_slist*    m_headers;
	eType		   m_request_type;
	string		   m_url;
	string		   m_request_data;
	curl_httppost* m_formpost;
	curl_httppost* m_lastptr;
	string         m_cookie_file;
	string		   m_sslca_file;
	int			   m_response_code;
	string		   m_response_header;
	string		   m_response_content;
};