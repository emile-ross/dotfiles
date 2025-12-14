#! /usr/bin/bash

# check for current dotfiles version
cd ~/.config/hypr
AWSNVERSION=$(awk 'NR==7 {print; exit}' hyprland.conf)
echo -e " The current version for the dotfiles is $AWSMVERSION \n"
cd ~

read -n1 -p "Do you want to save a copy of your old dotfiles before updating them? (Y/n): " ARCHIVE 
  if [[ $ARCHIVE == "Y" || $ARCHIVE == "y" ]]; then
  cd ~/.config/hypr #   Create an Archive of the hyprland config files
     mv hyprland.conf hyprland-old.conf
     mv hyprpaper.conf hyprpaper-old.conf
     mv hypridle.conf hypridle-old.conf
  cd ~/.config/nvim #  Create an Archive of the NeoVim config files ( not needed )
     mv init.lua init-old.lua
  cd ~
  fi

# ask for update then apply update (incomplete)
read -n1 -p "Do you want to update your dotfiles ? (Y/n): " UPDATE 
    if [[ $UPDATE == "Y" || $UPDATE == "y" ]]; then
    
    fi
