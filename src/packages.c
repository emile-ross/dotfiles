#include "header.h"

int install_package(distro_type distro, const char *pkginstallname)
{
	if (distro == arch_linux)
	{
		char *yay_cmd = "yay -S %s";
		int cmd_size = 1 + snprintf(NULL , 0, yay_cmd, pkginstallname);
		char *cmd_arch = malloc((unsigned)cmd_size);
		snprintf(cmd_arch, (size_t)cmd_size,
				yay_cmd, pkginstallname);
		system(cmd_arch);
		free(cmd_arch);
	}
	else if (distro == fedora_linux)
	{
		char *dnf_cmd = "sudo dnf install %s";
		int cmd_size = 1 + snprintf(NULL, 0, dnf_cmd, pkginstallname);
		char *cmd_deb = malloc((unsigned)cmd_size);
		snprintf(cmd_deb, (unsigned)cmd_size,
				dnf_cmd, pkginstallname);
		system(cmd_deb);
		free(cmd_deb);
	}
	else if ((distro == debian_linux) || (distro == ubuntu_linux))
	{
		char *apt_cmd = "sudo apt install %s";
		int cmd_size = 1 + snprintf(NULL, 0, apt_cmd, pkginstallname);
		char *cmd_deb = malloc((unsigned)cmd_size);
		snprintf(cmd_deb, (unsigned)cmd_size,
				apt_cmd, pkginstallname);
		system(cmd_deb);
		free(cmd_deb);
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
	snprintf(cmd, (unsigned)cmd_size,
			cmd_format, pkg);
}
