#pragma once

class UTLITY_EXT_CLASS regex_helper
{
public:
	regex_helper(void);
	~regex_helper(void);

public:
	static string		   replace(const string& src, const string& exp, const string& rp);
	static vector<string>  replace_list(const vector<string>& src, const string& exp, const string& rp);
	static string		   match(const string& src, const string& exp);
	static vector<string>  match_list(const string& src, const string& exp);
	static vector<string>  match_list(const vector<string>& src, const string& exp);
	static void			   trim(string& src, const string& searcher);
	static void		       trim_list(vector<string>& v_src_list, const string& searcher);
	static void            trim_left_right(string& src, const string& searcher);
	static void			   trim_left(string& src, const string& searcher);
	static void			   trim_right(string& src, const string& searcher);
};