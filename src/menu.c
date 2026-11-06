#include <stdio.h>

int main(int argc, char *argv[])
{
	int num_elements = argc - 1;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}
