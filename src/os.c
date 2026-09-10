#include "header.h"

#define MATCH(...) \
	table_matching(distro, (const char *[]){ __VA_ARGS__, NULL })

distro_type parent_d = unknown_distro;

distro_type validate_distro_name(const char *restrict distro);
bool table_matching(const char *restrict str, const char *restrict distros[]);
bool get_distro_name(char *output_distro, size_t output_len, const char *restrict tag_lookup);

int get_os_name(void)
{
	size_t size = 256;
	char *distro = malloc(size * sizeof(char));
	char *parent = NULL;

	/* compare the distro name agaisnt known distros or parents */
	if (!(get_distro_name(distro, size, "ID=")))
	{
		fprintf(stderr, "Failed to find a distro name under the ID tag in /etc/os-release\n");
		exit(-1);
	}

	parent_d = validate_distro_name(distro);

	if (parent_d == unknown_distro)
	{
		if (!(get_distro_name(parent, size, "ID_LIKE=")))
		{
			fprintf(stderr, "Failed to find a distro name under the ID_LIKE tag in /etc/os-release\n");
			exit(1);
		}
		error_message(UNSUPPORTED_DISTRO);
	}

	return 0;
}

bool get_distro_name(char *output_distro, size_t output_len, const char *restrict tag_lookup)
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
			if (output_distro == NULL)
			{
				if (output_len == 0)
				{
					output_len = 128;
				}
				output_distro = malloc(output_len);
			}
			/* store the value in char *output_distro */
			int ret = 1 + snprintf(output_distro, output_len, "%s", val);
			if (ret >= (signed)output_len)
			{
				/* not using realloc() because the possible copy 
				 * operation could be useless if the kernel can't extend our buffer */
				free(output_distro);
				output_len = (1 + strlen(val));
				output_distro = malloc(output_len);
				snprintf(output_distro, output_len, "%s", val);
			}
			fclose(fp);
			return true;
		}
	}
	fclose(fp);
	return false;
}

distro_type validate_distro_name(const char *restrict distro)
{
	if (MATCH("fedora", "rhel"))
	{
	    return fedora_linux;
	}
	else if (MATCH("arch linux", "arch"))
	{
		return arch_linux;
	}
	else if (MATCH("debian", "ubuntu", "zorin", "linuxmint"))
	{
		return debian_linux;
	}
	else
	{
		/* distro not found */
		return unknown_distro;
	}
}

bool table_matching(const char *restrict str, const char *restrict distros[])
{
	/* could provide a small performance boost when the string gets
	 * skipped for it's length rather than it's contents */
	size_t str_size = strlen(str);

	uint8_t i = 0;
	while (distros[i] != NULL)
	{
		size_t len = strlen(distros[i]);
		if (str_size >= len)
		{
			if (strncmp(str, distros[i], len) == 0)
			{
				return true;
			}
		}
		i++;
	}
	return false;
}
