#pragma once
#include "afxwin.h"


// dlg_changeip_setting �Ի���

class dlg_changeip_setting : public CDialog
{
	DECLARE_DYNAMIC(dlg_changeip_setting)

public:
	dlg_changeip_setting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg_changeip_setting();

// �Ի�������
	enum { IDD = IDD_DIALOG_DIAL_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboChangeType();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	void init(param_helper* param);
	void update_route();

private:
	CComboBox m_combo_changetype;
	CEdit	  m_edit_dialname;
	CEdit	  m_edit_dialpwd;
	CEdit	  m_edit_dialspan;
	CEdit	  m_edit_iptime;
	CEdit     m_edit_disconwait;
	CComboBox m_combo_route_type;
	CEdit     m_edit_route_address;

private:
	param_helper* m_param;
};
