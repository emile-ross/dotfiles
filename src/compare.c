#include "header.h"

bool cmp(const char *arg, const char *flag)
{
	if (strcmp(arg, flag) == 0)
	{
		return true;
	}

	return false;
}
