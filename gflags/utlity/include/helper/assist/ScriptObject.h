#pragma once

#include <xstring>
#include <list>
using namespace std;

#import "msscript.ocx" no_namespace

#define LANGUAGE_DEFAULT	_T("JScript")
#define RT_SCRIPT			_T("SCRIPT")
#define LANGUAGE_NAME_LEN	40
#define ERROR_DESC_LEN		256

#ifndef _UNICODE
typedef list<string> stl_string_list;
#else
typedef list<wstring> stl_string_list;
#endif

class CScriptObject
{
public:
	CScriptObject();
	~CScriptObject();

public:
	BOOL	SetTimeout(long lTime);
	LPCTSTR GetLanguage();
	void	SetLanguage(LPCTSTR szLanguage);
	int		GetMethodsCount() const;
	LPCTSTR GetNameAt(int index);
	void	Reset();
	bool	LoadScript(LPCTSTR szFilename);
	bool	LoadScriptResource(LPCTSTR lpName, LPCTSTR lpType, HINSTANCE hInstance);
	bool	AddScript(LPCTSTR szCode);
	bool	AddObject(LPCTSTR szObject, LPDISPATCH Object, bool AddMembers);
	LPCTSTR GetErrorString();
	bool	ExecuteStatement(LPCTSTR szStatement);
	bool	RunProcedure(LPCTSTR szProcName, SAFEARRAY** saParameters, VARIANT* varRet);

protected:
	void	CommonConstruct();
	bool	GetMethodsName();
	LPCTSTR GetScriptFunction(LPCTSTR name);

private:
	IScriptControlPtr m_pScript;							// The one and only script control
	stl_string_list   m_FunctionList;						// Function list
	TCHAR	          m_szLanguage[LANGUAGE_NAME_LEN+1];	// Current language
	TCHAR	          m_szError[ERROR_DESC_LEN+1];		    // Description error
};
