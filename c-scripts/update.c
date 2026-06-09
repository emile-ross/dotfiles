#include "dotfileshead.h"

int full_update(char archive_file, float pver)
{
	if (is_arch_bl)
	{
		/* checks if yay is installed only if the distro is arch */
		check_for_yay();
	}
	
	int VAWSM = (int)(pver * 100);
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

		bool archive_bl = y_n(archive_file);
		switch (prev_update_version)
		{
		case V_1:
			printf("\nUpdating from %f\n", pver);
			install_package(parent, "cava fuzzel kitty fastfetch waybar");
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_1_2:
		case V_1_3:
			install_package(parent, "hyprpaper btop");
			CAVA(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_1_4:
			BTOP(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2:
			install_package(parent, "gtklock");
			KITT(archive_bl, install_pkg_yn);
		__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_1:
			install_package(parent, "sway");
			WAYB(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_2:
			SWAY(archive_bl, install_pkg_yn);
			GTKL(archive_bl, install_pkg_yn);
			install_package(parent, "mpv swaylock");
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_3:
			NVIM(archive_bl, install_pkg_yn);
			FUZZ(archive_bl, install_pkg_yn);
			MPVF(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_4:
			install_package(parent, "hyprland bpytop hyprlock");
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_2_5:
		case V_3:
			BPYT(archive_bl, install_pkg_yn);
			__attribute__ ((fallthrough));	/* do not break because we are also installing everything below */
		case V_3_1:
			install_package(parent, "nvim");
			goto update_version_number;
		
		update_version_number:
			BASH();
			HYPR(archive_bl, install_pkg_yn);
			ZSHH(archive_bl, pver, install_pkg_yn);
			printf("Update completed!\n");
			break;
		
		default:
			error_message(UNKNOWN_AWSM_VERSION);
			break;
		}
	}

	return 0;
}

/* returns the VAWSM variable */
float* get_version(void) 
{
	/* create path to config */
	char *hyprpath_template = "%s/.config/hypr/hyprland.conf";
	size_t hyprpath_size = 1 + (size_t)snprintf(NULL, 0, "%s", hyprpath_template);
	char *hyprpath = malloc(hyprpath_size);

	snprintf(hyprpath, sizeof(hyprpath), hyprpath_template, home);
	/* set the hyprland path with username */

	/* open the file with hyprpath */
	FILE *file = fopen(hyprpath, "r");
	free(hyprpath);
	
	/* return error message when file isn't found */
	if (file == NULL) 
	{
		/* error message no such file or directory */
		error_message(NO_SUCH_FILE_OR_DIR);
		/* returns null if the file can't be opened/found */
		return NULL;
	}

	static float VAWSM[32] = {0};
	
	char line[384];
	while (fgets(line, sizeof(line), file)) 
	{
		/* this is true if the line contains:
		 * "# AWSMVERSION: " followed by a floating point number ranging from 0 to 9 */
		if (sscanf(line, "# AWSMVERSION: %31f[0-9.]", VAWSM) == 1)
		{
			fclose(file);
			return VAWSM;
		}
	}
	fclose(file);
	return 0;
}
