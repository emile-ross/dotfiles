#!/usr/bin/env bash

target_directory = ~/.config

config_install(){
	cp -if $1/* $(target_directory)/$1/
}

# this works and there is no reason for complicating it 
config_install bpytop
config_install btop
config_install fastfetch
config_install fish
config_install fuzzel
config_install gtklock
config_install hypr
config_install kitty
config_install mpv
config_install nvim
config_install rofi
config_install sway
config_install swaylock
config_install swaync
config_install waybar
config_install wlogout
