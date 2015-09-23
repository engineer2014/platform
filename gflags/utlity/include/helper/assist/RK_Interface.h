#pragma once

#include <afxinet.h> //������MFC CInternetSession���
#include <WinInet.h>
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

class CUtils;
class CGlobalMgr; 
class CSendData;

// ����ֻҪ���������Ľӿ�
// �޸���2015.5.11�����HOST��TIMEOUT�������ļ��У�Ϊ������ش�����Ϊ������
class CRK_Interface
{
public:
	CRK_Interface();
	~CRK_Interface();

public:
	// ����
	void InitConfig();

public:
	// �������,�����������Ҫ����
	// ����: lpSoftwareID:���ID; lpSoftwareKEY:���KEY; lpQuestionType:��Ŀ����;
	void RK_SoftInit(__in LPCTSTR lpSoftwareID, __in LPCTSTR lpSoftwareKEY, __in LPCTSTR lpQuestionType);
	// �û�����, �����������Ҫ����
	// ����: lpAccount:�û���; lpPassword:����;
	void RK_UserInit(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword);

	// �ϴ�ͼƬ�ֽ�����
	// ����: lpBytePic--ͼƬ�ֽ�����; dwPicSize--�ֽ����鳤��; szResult--���ؽ��
	// ����: TRUE��szResult=��ȷ��Ϣ, ����szResult=������Ϣ.
	BOOL RK_UploadPicByByte(__in LPBYTE lpBytePic, __in DWORD dwPicSize, __out CString& szResult);
	// �ϴ�����ͼƬ
	// ����: lpLocalPicPathName:������֤��ͼƬȫ·��; szResult:���ؽ��;
	// ����: TRUE��szResult=��ȷ��Ϣ, ����szResult=������Ϣ.
	BOOL RK_UploadPicByLocal(__in LPCTSTR lpLocalPicPathName, __out CString& szResult);
	// �ϴ�URLͼƬ
	// ����: lpURLPic:������֤��ͼƬ��URL����; szResult:���ؽ��;
	// ����: TRUE��szResult=��ȷ��Ϣ, ����szResult=������Ϣ.
	BOOL RK_UploadPicByURL(__in LPCTSTR lpURLPic, __out CString& szResult);
	// �ύ������ID
	// ����: lpErrorID:���ID;
	// ����: ���ؽ����Ϣ.
	BOOL RK_SubmitErrorID(__in LPCTSTR lpErrorID, __out CString& szResult);

	// ע��
	// ����: lpAccount:ע���û���; lpPassword:ע������; lpEmail:ע������; szResult:���ؽ��;
	BOOL RK_Register(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword, __in LPCTSTR lpEmail, __out CString& szResult);
	// ��ѯ
	// ����: lpAccount:�û���; lpPassword:����; szResult:���ؽ��;
	BOOL RK_Queryacct(__in LPCTSTR lpAccount, __in LPCTSTR lpPassword, __out CString& szResult);
	// ��ֵ
	// ����: lpAccount:�û���; lpCardID:��ֵ����; lpCardPassword:��ֵ����; szResult:���ؽ��;
	BOOL RK_Recharge(__in LPCTSTR lpAccount, __in LPCTSTR lpCardID, __in LPCTSTR lpCardPassword, __out CString& szResult);

private:
	BOOL AnswerUploadPic(const CString& fileName, const CString& imagePath, __out CString& szResult);
	BOOL AnswerUploadPic(const CString& fileName, const LPBYTE lpPicByte, DWORD dwPicSize, __out CString& szResult);
	BOOL SubmitPicURL(const CString& imageURL, __out CString& szResult);
	BOOL ProcAnswerResult(const string& response, __out CString& szResult);
};


// �ڲ�������,���߲��õ���
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

// �ڲ�������,���߲��õ���
class CGlobalMgr
{
public:
	CGlobalMgr(void);
	~CGlobalMgr(void);

	static void PostToRuoKuai(const string& targetPage, const string& postData, string& rspMsg, bool& successful);

public:
	static CString m_SoftwareID;			// ���ID
	static CString m_SoftwareKEY;			// ���KEY
	static CString m_QuestionType;			// ��Ŀ����
	static CString m_Account;				// �ʺ�
	static CString m_Password;				// ����
	static CString m_Host;				    // RK������(Ϊ������������ȶ����)
	static int     m_TimeOut;				// ��ʱʱ��(Ϊ������������ȶ����)
};

// �ڲ�������,���߲��õ���
#define HTTP_POST_GB2312	1	//���ͺͽ��յ���ҳ����
#define	HTTP_POST_UTF8		2

class CSendData
{
public:
	CSendData();
	virtual ~CSendData();
	void SetServerParam(TCHAR ServerName[100], TCHAR ObjectName[100], WORD Port);
	//����Э����������
	BOOL MakePostData(LPCTSTR pPostName, LPCTSTR pPostValue);
	BOOL MakePostData(LPCTSTR pPostName, int iPostValue);
	//���ʹ�ͼƬ������
	DWORD PostPicDataMethod(TCHAR PicPath[MAX_PATH], LPCTSTR pPostName,
		LPTSTR *pRecvData, DWORD &RecvSize,
		int	SendCode = HTTP_POST_GB2312,//���ͺͽ��յı���
		int RecvCode = HTTP_POST_GB2312,
		BOOL bIsByte = FALSE,
		LPBYTE lpPicByte = NULL,
		DWORD dwPicByteSize = 0);
	//�����ı�������
	DWORD PostDataMethod(LPCTSTR strDataSend, int DataSize,
		LPTSTR *pRecvData, DWORD &RecvSize,
		int	SendCode = 1, int RecvCode = 1);
private:
	CString			m_strBoundary;	//���ݷָ���
	CString			m_strHeaderData;	//Э��ͷ����
	CString			m_strPostData;	//Э����������
	CString			m_strEndData;	//Э��β����

	void MakeHeaderData();	//����Э��ͷ������
	void MakeEndData();		//����Э��β������
	void MakePostPicData(LPCTSTR pPostName, LPCTSTR pPostValue);	//����ͼƬǰ׺����

	//����ֵΪͼƬ��С������ֵΪ0��ʾ�����ڡ�
	DWORD GetExistPic(TCHAR PicPath[MAX_PATH]);
	//����������
	INTERNET_PORT m_nPort;
	TCHAR m_tzObjectName[100];
	TCHAR m_tzServerName[100];
	/////����ת��/////////////////////////////////////////////////////////////
	char	* m_lpUTF8;			//UTF8���뻺��ָ��
	char	* m_lpMultiByte;	//Multil���ֽڱ���ָ��
	wchar_t	* m_wpWideChar;		//Widechar���뻺��ָ��
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