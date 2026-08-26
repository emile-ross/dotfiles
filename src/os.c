#include "header.h"

distro_type parent_d;

int get_os_name(void)
{
	/* open /etc/os-release */
	FILE *fp = fopen("/etc/os-release", "r");
	
	/* fallback to /usr/lib if /etc/os-release fails */
	if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
	/* error checking */
	if (!fp) error_message(RENAME_FAIL);
	
	char t_line[256];
	size_t size = 128;
	char *distro = malloc(size);
	char *parent = malloc(size);

	while (fgets(t_line, sizeof(t_line), fp)) 
	{
		/* store the value after '=' in char val */
		char *val = strchr(t_line, '=') + 1;

		/* remove trailing newline */
		val[strcspn(val, "\"\n")] = '\0'; 

		bool noDist = true;
		
		if (strncmp(t_line, "ID=", 3) == 0)
		{
			strcpy(distro, val);	/* store the value in char distro */
			noDist = false;
		}


		if (scmp(distro, "arch linux"))
		{
			parent_d = arch_linux;
		}
		else if (cmp(distro, "debian", "ubuntu"))
		{
			parent_d = debian_linux;
		}

		if (strncmp(t_line, "ID_LIKE=", 8) == 0)
		{
			strcpy(parent, val);	/* store the value in char parent */
			noDist = false;
		}

		if (noDist)
		{
			fprintf(stderr, "failed to get the distro name in /etc/os-release\n");
			free(parent);
			free(distro);
			exit(1);
		}
	}

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
	fclose(fp);
	free(distro);
	free(parent);

	return 0;
}


