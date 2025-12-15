#! /usr/bin/bash

# check for current dotfiles version
cd ~/.config/hypr
AWSMV=$(awk 'NR==7 {print; exit}' hyprland.conf)
echo -e " The current version for the dotfiles is $AWSMV \n"
cd ~

read -n1 -p "Do you want to save a copy of your old dotfiles before updating them? (Y/n): " ARCHIVE 
  if [[ $ARCHIVE == "Y" || $ARCHIVE == "y" ]]; then
  AWV="v$AWSM"
  cd ~/.config/hypr #   Create an Archive of the hyprland config files
     mv hyprland.conf hyprland-old$AWV.conf
     mv hyprpaper.conf hyprpaper-old$AWV.conf
     mv hypridle.conf hypridle-old$AWV.conf
  cd ~/.config/nvim #  Create an Archive of the NeoVim config files ( not needed )
     mv init.lua init-old$AWV.lua
  cd ~
  fi

# ask for update then apply update (incomplete)
read -n1 -p "Do you want to update your dotfiles ? (Y/n): " UPDATE 
    if [[ $UPDATE == "Y" || $UPDATE == "y" ]]; then
    
    fi
