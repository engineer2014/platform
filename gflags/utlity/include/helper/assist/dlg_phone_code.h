#pragma once
#include "afxwin.h"


// dlg_phone_code 对话框

class dlg_phone_code : public CDialog
{
	DECLARE_DYNAMIC(dlg_phone_code)

public:
	dlg_phone_code(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlg_phone_code();

// 对话框数据
	enum { IDD = IDD_DIALOG_PHONE_CODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();

public:
	void   init(string str_phone, bool binput_number = true);
	string get_phone_number();
	string get_phone_response();

private:
	CEdit m_edit_phonenumber;
	CEdit m_edit_phoneresponse;
	bool  m_input_number;

	string m_str_phonenumber;
	string m_str_phoneresponse;
};
