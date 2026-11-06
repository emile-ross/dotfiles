#!/usr/bin/env bash

target_directory="~/.config"

config_install(){
	cp -if $1/* $target_directory/$1/
}


# make a list of all configs and install all of them one at a time
configs='bpytop btop fastfetch fish fuzzel gtklock hypr kitty mpv nvim rofi sway swaylock swaync waybar wlogout'

for config in $configs
do
	config_install $config
done
