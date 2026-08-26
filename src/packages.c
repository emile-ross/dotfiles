#include "header.h"

int install_package(distro_type distro, const char *pkginstallname)
{
	if (distro == arch_linux)
	{
		int cmd_size = 1 + snprintf(NULL , 0, "yay -S %s", pkginstallname);
		char *cmd_arch = malloc((unsigned)cmd_size);
		snprintf(cmd_arch, (size_t)cmd_size,
				"yay -S %s", pkginstallname);
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
		int cmd_size = 1 + snprintf(NULL, 0, "sudo apt install %s", pkginstallname);
		char *cmd_deb = malloc((unsigned)cmd_size);
		snprintf(cmd_deb, (unsigned)cmd_size,
				"sudo apt install %s", pkginstallname);
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
