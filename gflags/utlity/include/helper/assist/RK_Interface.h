#pragma once

#include <afxinet.h> //定义了MFC CInternetSession类等
#include <WinInet.h>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

class CUtils;
class CGlobalMgr; 
class CSendData;

// 作者只要调用这个类的接口
// 修改于2015.5.11，添加HOST，TIMEOUT到配置文件中，为解决返回打码结果为空问题
class CRK_Interface
{
public:
	CRK_Interface();
	~CRK_Interface();

public:
	// 配置
	void InitConfig();

public:
	// 软件设置,这个函数必须要调用
	// 参数: lpSoftwareID:软件ID; lpSoftwareKEY:软件KEY; lpQuestionType:题目类型;
	void RK_SoftInit(__in LPCTSTR lpSoftwareID, __in LPCTSTR lpSoftwareKEY, __in LPCTSTR lpQuestionType);
	// 用户设置, 这个函数必须要调用
	// 参数: lpAccount:用户名; lpPassword:密码;
	void RK_UserInit(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword);

	// 上传图片字节数组
	// 参数: lpBytePic--图片字节数组; dwPicSize--字节数组长度; szResult--返回结果
	// 返回: TRUE则szResult=正确信息, 否则szResult=错误信息.
	BOOL RK_UploadPicByByte(__in LPBYTE lpBytePic, __in DWORD dwPicSize, __out CString& szResult);
	// 上传本地图片
	// 参数: lpLocalPicPathName:本地验证码图片全路径; szResult:返回结果;
	// 返回: TRUE则szResult=正确信息, 否则szResult=错误信息.
	BOOL RK_UploadPicByLocal(__in LPCTSTR lpLocalPicPathName, __out CString& szResult);
	// 上传URL图片
	// 参数: lpURLPic:网络验证码图片的URL链接; szResult:返回结果;
	// 返回: TRUE则szResult=正确信息, 否则szResult=错误信息.
	BOOL RK_UploadPicByURL(__in LPCTSTR lpURLPic, __out CString& szResult);
	// 提交错误结果ID
	// 参数: lpErrorID:结果ID;
	// 返回: 返回结果信息.
	BOOL RK_SubmitErrorID(__in LPCTSTR lpErrorID, __out CString& szResult);

	// 注册
	// 参数: lpAccount:注册用户名; lpPassword:注册密码; lpEmail:注册邮箱; szResult:返回结果;
	BOOL RK_Register(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword, __in LPCTSTR lpEmail, __out CString& szResult);
	// 查询
	// 参数: lpAccount:用户名; lpPassword:密码; szResult:返回结果;
	BOOL RK_Queryacct(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword, __out CString& szResult);
	// 充值
	// 参数: lpAccount:用户名; lpCardID:充值卡号; lpCardPassword:充值密码; szResult:返回结果;
	BOOL RK_Recharge(__in LPCTSTR lpAccount, __in LPCTSTR lpCardID, __in LPCTSTR lpCardPassword, __out CString& szResult);

private:
	BOOL AnswerUploadPic(const CString& fileName, const CString& imagePath, __out CString& szResult);
	BOOL AnswerUploadPic(const CString& fileName, const LPBYTE lpPicByte, DWORD dwPicSize, __out CString& szResult);
	BOOL SubmitPicURL(const CString& imageURL, __out CString& szResult);
	BOOL ProcAnswerResult(const string& response, __out CString& szResult);
};


// 内部功能类,作者不用调用
class CUtils
{
public:
	CUtils(void);
	~CUtils(void);

	static void PostRequest(const string& hostName, const string& pathName, const string& postData, string& response);
	static bool PostHttpPage(const string& hostName, const string& pathName, const string& postData, string& response);
	static void ParseResponse(const string& response, string& rspMsg, bool& successful);
	static void GetXMLFirstTagValue(const string& xmlStr, const string& tag, string& tagValue);
	static void ProcessRspMsg(const string& rspMsg, bool rspResult);
	static void ProcessChineseMessyCode(string& input);
};

// 内部功能类,作者不用调用
class CGlobalMgr
{
public:
	CGlobalMgr(void);
	~CGlobalMgr(void);

	static void PostToRuoKuai(const string& targetPage, const string& postData, string& rspMsg, bool& successful);

public:
	static CString m_SoftwareID;			// 软件ID
	static CString m_SoftwareKEY;			// 软件KEY
	static CString m_QuestionType;			// 题目类型
	static CString m_Account;				// 帐号
	static CString m_Password;				// 密码
	static CString m_Host;				    // RK服务器(为若快服务器不稳定添加)
	static int     m_TimeOut;				// 超时时间(为若快服务器不稳定添加)
};

// 内部功能类,作者不用调用
#define HTTP_POST_GB2312	1	//发送和接收的网页编码
#define	HTTP_POST_UTF8		2

class CSendData
{
public:
	CSendData();
	virtual ~CSendData();
	void SetServerParam(TCHAR ServerName[100], TCHAR ObjectName[100], WORD Port);
	//构造协议数据内容
	BOOL MakePostData(LPCTSTR pPostName, LPCTSTR pPostValue);
	BOOL MakePostData(LPCTSTR pPostName, int iPostValue);
	//发送带图片的数据
	DWORD PostPicDataMethod(TCHAR PicPath[MAX_PATH], LPCTSTR pPostName,
		LPTSTR *pRecvData, DWORD &RecvSize,
		int	SendCode = HTTP_POST_GB2312,//发送和接收的编码
		int RecvCode = HTTP_POST_GB2312,
		BOOL bIsByte = FALSE,
		LPBYTE lpPicByte = NULL,
		DWORD dwPicByteSize = 0);
	//发送文本类数据
	DWORD PostDataMethod(LPCTSTR strDataSend, int DataSize,
		LPTSTR *pRecvData, DWORD &RecvSize,
		int	SendCode = 1, int RecvCode = 1);
private:
	CString			m_strBoundary;	//数据分隔符
	CString			m_strHeaderData;	//协议头数据
	CString			m_strPostData;	//协议正文数据
	CString			m_strEndData;	//协议尾数据

	void MakeHeaderData();	//构造协议头部数据
	void MakeEndData();		//构造协议尾部数据
	void MakePostPicData(LPCTSTR pPostName, LPCTSTR pPostValue);	//构造图片前缀数据

	//返回值为图片大小，返回值为0表示不存在。
	DWORD GetExistPic(TCHAR PicPath[MAX_PATH]);
	//服务器参数
	INTERNET_PORT m_nPort;
	TCHAR m_tzObjectName[100];
	TCHAR m_tzServerName[100];
	/////编码转换/////////////////////////////////////////////////////////////
	char	* m_lpUTF8;			//UTF8编码缓存指针
	char	* m_lpMultiByte;	//Multil多字节编码指针
	wchar_t	* m_wpWideChar;		//Widechar编码缓存指针
	int		m_nUTF8Len;
	int		m_nMultiByteLen;
	int		m_nWideCharLen;

	void WideCharToUTF8(LPCWSTR wpWideData, int WideLen);
	void MultiByteToUTF8(LPCSTR lpMultiData, int MultiLen);
	void UTF8ToWideChar(LPCSTR pUTF8, int UTF8Len);
	void UTF8ToMultiByte(LPCSTR pUTF8, int UTF8Len);
	void MultiToWide(LPCSTR strDataSend, int DataSize);
	void MultiToMulti(LPCSTR strDataSend, int DataSize);
	void WideToMulti(LPCWSTR wpWideData, int WideLen);

};