#include "header.h"

void pkg_cmd(const char *cmd_format, char *pkg);

int install_package(distro_type distro, const char *pkginstallname)
{
	if (distro == arch_linux)
	{
		pkg_cmd("yay -S %s", pkginstallname);
	}
	else if (distro == fedora_linux)
	{
		pkg_cmd("sudo dnf install %s", pkginstallname);
	}
	else if ((distro == debian_linux) || (distro == ubuntu_linux))
	{
		pkg_cmd("sudo apt install %s", pkginstallname);
	}
	else 
	{
		printf("Your distribution is not supported.\n");
		wait_for_timeout(SHORT_TIMER, 1);
	}
	
	return 0;
}

void pkg_cmd(const char *cmd_format, char *pkg)
{
	int cmd_size = 1 + snprintf(NULL, 0, cmd_format, pkg);

	char *cmd = malloc((unsigned)cmd_size);
	int ret = snprintf(cmd, (unsigned)cmd_size, cmd_format, pkg);

	if (ret > cmd_size)
	{
		error_message(BUFFER_SIZE_FAIL);
	}

	system(cmd);
	free(cmd);
}
