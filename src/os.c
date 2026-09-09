#include "header.h"

distro_type parent_d;

int get_os_name(void)
{
	/* open /etc/os-release */
	FILE *fp = fopen("/etc/os-release", "r");
	
	/* fallback to /usr/lib if /etc/os-release fails */
	if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
	/* error checking */
	if (fp == NULL) error_message(FILE_OS_RELEASE_FAIL);
	
	size_t size = 256;
	char *distro = malloc(size);
	char *parent = NULL;

	if (cmp(distro, "arch linux", "arch"))
	{
		parent_d = arch_linux;
		if (verbose)
			printf("Distro is arch linux\n");
	}
	else if (scmp(distro, "fedora"))
	{
		/* distro found */
		parent_d = fedora_linux;
	}
	else if (cmp(distro, "debian", "ubuntu"))
	{
		parent_d = debian_linux;
	}

	}
	fclose(fp);

	const uint8_t max_dists = 5;
	char *distros[max_dists];
	uint8_t i = 0;
	for (; i < strlen(parent); i++)
	{
		size_t len = strcspn(parent, " \0");
		parent[len] = '\0';
		strcpy(distros[i], parent);
		
		*(parent) += len;
	}
	distros[i++] = NULL;

	for (uint8_t j = 0; j <= i; j++)
	{
		if (scmp(distros[j], "arch linux"))
		{
			parent_d = arch_linux;
		}
		if (cmp(distros[j], "arch linux", "ubuntu") || scmp(distros[j], "zorin"))
		{
			parent_d = debian_linux;
		}
	}

	/* close file */
	free(distro);
	free(parent);

	return 0;
}


char *get_distro_name(void)
{
	while (fgets(t_line, sizeof(t_line), fp)) 
	{
		char *val = strchr(t_line, '=') + 1;

		/* remove trailing newline */
		val[strcspn(val, "\"\n")] = '\0'; 

		if (strncmp(t_line, "ID=", 3) == 0)
		{
			strcpy(distro, val);	/* store the value in char distro */
			if (verbose)
				printf("line in config : %s\ndistro: %s\n", val, distro);
		}
		else if (strncmp(t_line, "ID_LIKE=", 8) == 0)
		{
			if (parent != NULL)
				fprintf(stderr, "warning: reallocating parent distro buffer\n");
			parent = malloc(size);
			if (parent == NULL)
				error_message(MALLOC_FAIL);

			strcpy(parent, val);	/* store the value in char parent */
		}
	}
}
