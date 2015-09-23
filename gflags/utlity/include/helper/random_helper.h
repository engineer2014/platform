#pragma once

class UTLITY_EXT_CLASS random_helper
{
public:
	random_helper(void);
	~random_helper(void);

public:
	static void   init_seed();
	static int    rand_int(int nstart, int nend);
	static double rand_double(double nstart, double nend);
	static char   rand_char(int type = 0);
};
