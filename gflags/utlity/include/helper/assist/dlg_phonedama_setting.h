#pragma once
#include "afxwin.h"

// dlg_phonedama_setting 对话框

class dlg_phonedama_setting : public CDialog
{
	DECLARE_DYNAMIC(dlg_phonedama_setting)

public:
	dlg_phonedama_setting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlg_phonedama_setting();

// 对话框数据
	enum { IDD = IDD_DIALOG_PHONEDAMA_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
