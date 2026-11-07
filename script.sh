#!/usr/bin/env bash

target_directory="~/.config"

config_install(){
	cp -if $1/* $target_directory/$1/
}

package_install(){
	cat $1 | sh
}
	


# make a list of all configs and install all of them one at a time
configs='bpytop btop fastfetch fish fuzzel gtklock hypr kitty mpv nvim rofi sway swaylock swaync waybar wlogout'

# install all configs
for config in $configs
do
	config_install $config
	echo "Do you want to install $config? (Y/n)"
	read input
	if [ $input -eq y ]
	then
		# execute installation script for the specific program
		package_install $config
	fi
done

