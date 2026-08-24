#include "header.h"

bool scmp(const char *arg, const char *flag)
{
	if (strcmp(arg, flag) == 0)
	{
		return true;
	}

	return false;
}

bool cmp(const char *arg, const char *s_flag, const char *l_flag)
{
	if (strcmp(arg, s_flag) == 0)
	{
		return true;
	}
	else if (strcmp(arg, l_flag) == 0)
	{
		return true;
	}

	return false;
}
