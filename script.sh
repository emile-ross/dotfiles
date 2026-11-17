#!/usr/bin/env bash

target_directory="$HOME/.config"

config_install(){
	name=${1,,}
	if [ -z $LANG ] ;
	then
		echo "export LANG=en_US.UTF-8" >> $HOME/.bashrc
		echo "export LANG=en_US.UTF-8" >> $HOME/.zshrc
	fi
	
	mkdir -p $target_directory/$name
	cp -f .config/$name/* $target_directory/$name/
}

package_install(){
	cat $1 | sh
}

function yes_no
{
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
configs='alacritty bpytop btop fastfetch fish fuzzel gtklock hypr kitty mpv nvim rofi sway swaylock swaync waybar wlogout'


if [ $# -eq 1 ] ; 
then
	config_install $1
elif [ $# -gt 1 ] ; 
then
	i=0
	for arg in $@
	do
		echo "argument #$i $arg"
		if [ "$arg" == "-p" ] || [ "$arg" == "--package" ] ;
		then
			sudo pacman -S "$2"
			echo "package flag was found"
		elif [ "$arg" == "-c" ] || [ "$arg" == "--config" ] ;
		then
			config_install "$2"
		fi
		((i++))
	done
else
	echo -e "Installing all configurations... \n"
	yes_count=0
	for config in $configs
	do
		yes_no "Do you want to install $config?" "Y/n"
		if [ $? -eq 0 ]
		then
			# execute installation script for the specific program
			yes_no "Install configurations for $config" "Y/n" && ((yes_count++)) && config_install "$config"
			yes_no "Install package $config" "Y/n" && package_install "$config"
			echo "$yes_count"
		fi
	done
fi

# install all configs
