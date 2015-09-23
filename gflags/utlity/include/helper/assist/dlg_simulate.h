#pragma once

#ifdef _WIN32_WCE
#error "Windows CE 不支持 CDHtmlDialog。"
#endif 

// dlg_simulate 对话框
// 辅助simulate_helper实现
class dlg_simulate : public CDHtmlDialog
{
	DECLARE_DYNCREATE(dlg_simulate)

public:
	dlg_simulate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlg_simulate();
// 重写
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 对话框数据
	enum { IDD = IDD_DLG_SIMULATE, IDH = IDR_HTML_DLG_SIMULATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()

public:
	CWnd*		get_html_wnd();
	void		navigate(CString strUrl);
	bool		input_txt(CString element_id, CString strContent);
	bool		select_item(CString element_id, int index);
	bool		click_button(CString element_id);
	void		click_pos(int x, int y, bool bshow);
	CString		get_page_content(CString strUrl);
	CString		get_page_content();
	VARIANT		StringToVariant(CString str);
	CComVariant StringToComVariant(CString str);

public:
	CComQIPtr<IHTMLElement> get_element(CString element_id);
	CComQIPtr<IHTMLElement> get_element(CString tag_name, CString class_name, int index);
	CComQIPtr<IHTMLElement> get_element_ex(CString tag_name, CString txt_content, int index);

public:
	virtual void OnBeforeNavigate(LPDISPATCH pDisp, LPCTSTR szUrl);

	DECLARE_EVENTSINK_MAP()
	afx_msg void OnNewWindow3(LPDISPATCH* ppDisp, BOOL* Cancel, unsigned long dwFlags, LPCTSTR bstrUrlContext, LPCTSTR bstrUrl);

public:
	// 等待完成事件
	void WaitCompleteEvent(DWORD dwMilliseconds);

	// 重置完成事件
	void ResetCompleteEvent();

	// 设置完成事件
	void SetCompleted();

	// 加载页面完成
	void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl);

private:
	HANDLE m_etComplete;
};
