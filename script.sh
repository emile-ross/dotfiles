#!/usr/bin/env bash

target_directory="$HOME/.config"

config_install()
{
	name=${1,,}
	if [ -z $LANG ] ;
	then
		echo "export LANG=en_US.UTF-8" >> $HOME/.bashrc
		echo "export LANG=en_US.UTF-8" >> $HOME/.zshrc
	fi
	
	mkdir -p $target_directory/$name
	cp -f .config/$name/* $target_directory/$name/
}

package_install()
{
	# make package name lowercase (for standard naming)
	package=${1,,}
	if [ $# -gt 0 ] ;
	then
		echo "Installing $package"
		sudo pacman -S "$package"
		if [ "$EUID" -eq 0 ] ; 
		then
			echo "Installed $package successfully!\n"
		fi
	fi
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
	index=1
	if [[ ${!index:0:1} = "-" ]] ;
	then
		echo -e "you probably didn't want to install a file starting with a '-'"
	fi
	echo -e "\n"
	config_install $1
elif [ $# -gt 1 ] ; 
then
	i=0
	for arg in $@
	do
		next_index=$(($i + 2))
		next_argument=${!next_index}
		echo "argument #$i $arg"
		if [ "$arg" == "-p" ] || [ "$arg" == "--package" ] ;
		then
			sudo pacman -S "$next_argument"
			echo "package flag was found"
		elif [ "$arg" == "-v" ] || [ "$arg" == "--version" ] ;
		then
			get_diff "$next_argument"
		elif [ "$arg" == "-c" ] || [ "$arg" == "--config" ] ;
		then
			config_install "$next_argument"
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
			yes_no "Install configurations for $config" "Y/n"
			if [ "$EUID" -eq 0 ] ;
			then
				((config_yes_count++))
				config_install "$config"
			fi
			yes_no "Install package $config" "Y/n"
			if [ "$EUID" -eq 0 ] ;
			then
				((package_yes_count++))
				package_install "$config"
			fi
			echo "$yes_count"
		fi
	done
fi
