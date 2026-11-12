#!/usr/bin/env bash

target_directory="~/.config"

config_install(){
	cp -if $1/* $target_directory/$1/
}

package_install(){
	cat $1 | sh
}

function y_n {
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

# install all configs
for config in $configs
do
	echo "Do you want to install $config? (Y/n)"
	read input
	if [ $input -eq y ]
	then
		# execute installation script for the specific program
		package_install $config
		config_install $config
	fi
done

