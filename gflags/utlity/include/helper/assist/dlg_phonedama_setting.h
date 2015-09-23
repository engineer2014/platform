#pragma once
#include "afxwin.h"

// dlg_phonedama_setting �Ի���

class dlg_phonedama_setting : public CDialog
{
	DECLARE_DYNAMIC(dlg_phonedama_setting)

public:
	dlg_phonedama_setting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg_phonedama_setting();

// �Ի�������
	enum { IDD = IDD_DIALOG_PHONEDAMA_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboDama();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnQuery();
	afx_msg void OnBnClickedBtnGo();

public:
	void init(param_helper* param);

private:
	CComboBox m_combo_dama;
	CEdit     m_edit_user;
	CEdit     m_edit_pwd;

private:
	param_helper* m_param;
};
