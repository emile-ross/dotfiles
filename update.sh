#! /usr/bin/bash

# check for current dotfiles version
cd ~/.config/hypr

AWSNVERSION=$(awk 'NR==1 {print; exit}' hyprland.conf)
echo -e " The current version for the dotfiles is $AWSMVERSION \n"
