#pragma once
#include <atlimage.h>

// dlg_verifycode 对话框

class dlg_verifycode : public CDialog
{
	DECLARE_DYNAMIC(dlg_verifycode)

public:
	dlg_verifycode(CString str_pic, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlg_verifycode();

// 对话框数据
	enum { IDD = IDD_DIALOG_VERIFY_CODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();

public:
	void   init(CString str_title);
	string get_verify_code();

private:
	int		m_min_x;		// 最小宽度
	int     m_min_y;		// 最小高度
	CImage	m_image;		// 图片
	CString m_str_pic;		// 图片路径
	CString m_str_code;		// 识别结果

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};
