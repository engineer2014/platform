#pragma once
#include <atlimage.h>

// dlg_verifycode �Ի���

class dlg_verifycode : public CDialog
{
	DECLARE_DYNAMIC(dlg_verifycode)

public:
	dlg_verifycode(CString str_pic, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlg_verifycode();

// �Ի�������
	enum { IDD = IDD_DIALOG_VERIFY_CODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();

public:
	void   init(CString str_title);
	string get_verify_code();

private:
	int		m_min_x;		// ��С���
	int     m_min_y;		// ��С�߶�
	CImage	m_image;		// ͼƬ
	CString m_str_pic;		// ͼƬ·��
	CString m_str_code;		// ʶ����

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};
