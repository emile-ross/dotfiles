#include "header.h"

distro_type parent_d;

distro_type validate_distro_name(const char *restrict distro);

int get_os_name(void)
{
	size_t size = 256;
	char *distro = malloc(size);
	char *parent = NULL;


	/* compare the distro name agaisnt known distros or parents */
	parent_d = validate_distro_name(distro);

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


char *get_distro_name(char *output_distro, size_t output_len, const char *restrict tag_lookup)
{
	/* open /etc/os-release */
	FILE *fp = fopen("/etc/os-release", "r");
	
	/* fallback to /usr/lib if /etc/os-release fails */
	if (!fp) fp = fopen("/usr/lib/os-release", "r"); 
	/* error checking */
	if (fp == NULL) error_message(FILE_OS_RELEASE_FAIL);
	
	char t_line[320];
	size_t tag_length = strlen(tag_lookup);
	while (fgets(t_line, sizeof(t_line), fp)) 
	{
		char *val = strchr(t_line, '=') + 1;

		/* remove trailing newline */
		val[strcspn(val, "\"\n")] = '\0'; 

		/* match the tag being passed into the function to the line start 
		 * if it matches, this stores the remainder of the line into the
		 * buffer '' */
		if (strncmp(t_line, tag_lookup, tag_length) == 0)
		{	
			/* store the value in char *output_distro */
			int ret = 1 + snprintf(distro, output_len, "%s", val);
			if (ret >= output_len)
			{
				/* not using realloc() because the possible copy 
				 * operation could be useless if the kernel can't extend our buffer */
				free(output_distro);
				output_len = (1 + strlen(val));
				output_distro = malloc();
				snprintf(distro, output_len, "%s", val);
				return distro;
			}
		}
	}
	fclose(fp);
	return NULL;
}

distro_type validate_distro_name(const char *restrict distro)
{
	if (cmp(distro, "arch linux", "arch"))
	{
		return arch_linux;
	}
	else if (scmp(distro, "fedora"))
	{
		/* distro found */
		return fedora_linux;
	}
	else if (cmp(distro, "debian", "ubuntu"))
	{
		return debian_linux;
	}
	else
	{
		return unknown_distro;
	}
}
