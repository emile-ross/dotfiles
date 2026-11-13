#!/usr/bin/env bash

target_directory="$HOME/.config"

config_install(){
	mkdir -p $target_directory/$1
	cp -f .config/$1/* $target_directory/$1/
}

package_install(){
	cat $1 | sh
}

function yes_no {
	while true; do
		echo -n "$1 [$2]:"
		read yn
		case $yn in
			[Yy]*) return 0  ;;  
			[Nn]*) echo "Aborted" ; return  1 ;;
		esac
	done
}
	


# make a list of all configs and install all of them one at a time
configs='bpytop btop fastfetch fish fuzzel gtklock hypr kitty mpv nvim rofi sway swaylock swaync waybar wlogout'

if [ $# -eq 1 ]; then
	config_install $1
else
	for config in $configs
	do
		echo "Do you want to install $config? (Y/n)"
		read input
		if [ $input -eq y ]
	
		then
			# execute installation script for the specific program
			yes_no "Install configurations for $config" "Y/n" && config_install $config
			yes_no "Install package $config" "Y/n" && package_install $config
			
		fi
	done
fi


# install all configs

