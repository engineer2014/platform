#pragma once
#include "afxwin.h"


// dlg_verify_setting �Ի���

class dlg_verify_setting : public CDialog
{
	DECLARE_DYNAMIC(dlg_verify_setting)

public:
	dlg_verify_setting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg_verify_setting();

// �Ի�������
	enum { IDD = IDD_DIALOG_VERIFY_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboVerify();
	afx_msg void OnBnClickedBtnQuerytf();
	afx_msg void OnBnClickedBtnGo();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	void init(param_helper* param);

private:
	CComboBox m_combo_verify;
	CEdit     m_edit_user;
	CEdit     m_edit_pwd;

private:
	param_helper* m_param;
};
