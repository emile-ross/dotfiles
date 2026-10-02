#include "header.h"

int full_update(float version)
{
	/*
	if (is_arch_bl)
	{
		checks if yay is installed only if the distro is arch
		check_for_yay();
	}
	*/
	
	int VAWSM = (int)(version * 100);
	bool install_pkg_yn = false;
	
	df_version prev_update_version = (df_version)VAWSM;
	
	if (prev_update_version == (df_version)STABLE)
	{
		printf("\nYou are running the latest stable version.\n");
		block(true);
		clearbuffer();
	}
	else
	{
		switch (prev_update_version)
		{
		case STABLE:
			printf("\nYou are running the latest stable version.\n");
			block(true);
			return 0;
			break;
		
		case LATEST:
			printf("You are using the latest version, it is often ahead of the latest stable release\n");
			block(true);
			return 0;
			break;
		default:
			break;
		}

		switch (prev_update_version)
		{
		case V_1:
			printf("\nUpdating from %f\n", version);
			install_package(parent_d, "cava fuzzel kitty fastfetch waybar");
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_1_2:
		case V_1_3:
			install_package(parent_d, "hyprpaper btop");
			/* CAVA(archive_bl, install_pkg_yn); */
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_1_4:
			/* BTOP(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	do not break because we are also installing everything below */
		case V_2:
			install_package(parent_d, "gtklock");
			/* KITT(archive_bl, install_pkg_yn); */
		__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_1:
			install_package(parent_d, "sway");
			/* WAYB(archive_bl, install_pkg_yn); */
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_2:
			/* SWAY(archive_bl, install_pkg_yn); */
			/* GTKL(archive_bl, install_pkg_yn); */
			install_package(parent_d, "mpv swaylock");
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_3:
			/* NVIM(archive_bl, install_pkg_yn); */
			/* FUZZ(archive_bl, install_pkg_yn); */
			/* MPVF(archive_bl, install_pkg_yn); */
			/* __attribute__ ((fallthrough));	do not break because we are also installing everything below */
		case V_2_4:
			install_package(parent_d, "hyprland bpytop hyprlock");
			__attribute__ ((fallthrough));	 /* do not break because we are also installing everything below */
		case V_2_5:
		case V_3:
			/* BPYT(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	do not break because we are also installing everything below */
		case V_3_1:
			install_package(parent_d, "nvim");
			goto update_version_number;
		
		update_version_number:
			/* BASH(); */
			/* HYPR(archive_bl, install_pkg_yn); */
			/* ZSHH(archive_bl, version, install_pkg_yn); */
			printf("Update completed!\n");
			break;
		
		default:
			error_message(UNKNOWN_AWSM_VERSION);
			break;
		}
	}

	return 0;
}

