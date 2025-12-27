#! /usr/bin/bash

# check if yay is installed
cd ~
ISYAY=/sbin/yay
if [ -f $ISYAY ] ; then
echo -e " Yay is now installed, congrats! \n"
else
   # install yay if it isn't already installed
   read -n1 -p "Yay is not installed, do you want to install it? (Y/n): " YAY
   if [[ $YAY == "Y" || $YAY == "y" ]]; then
   # install yay since it is needed to install the dependencies
   
      # check if makepkg is installed
      if ! command -v makepkg &>/dev/null; then
      echo -e "\nMakepkg is not installed. Installing 'base-devel' package group to proceed...\n"
      sudo pacman -S --noconfirm base-devel
	  
      # Check if makepkg is available after installing base-devel
      if ! command -v makepkg &>/dev/null; then
        echo -e "Makepkg installation failed. Please check your system configuration.\n"
        exit 1
      else
        echo -e "Makepkg has been successfully installed!\n"
	  fi
    else
      echo -e "Makepkg is already installed.\n"
    fi
   git clone https://aur.archlinux.org/yay.git
   cd yay
   makepkg -si
   cd ..
   echo -e "\nYay is installed, congrats!"

   else
      echo -e "\nYay is needed in order to proceed with the script."
      exit 1
   fi
fi

# install dependencies
read -n1 -p 'Do you want to proceed with the installation of packages? (Y/n) ' PKGINSTALL
if [[ $PKGINSTALL == "Y" || $PKGINSTALL == "y" ]]; then
	yay -S --noconfirm hyprland kitty waybar gtklock hyprpaper wofi
fi

# Propose saving the old config files before performing the update 

read -n1 -p "Do you want to save a copy of your old dotfiles before updating them? (Y/n): " ARCHIVE 
if [[ $ARCHIVE == "Y" || $ARCHIVE == "y" ]]; then
    OLD_VERSION="0"
	# old version is 0 since this is the first install
    # Archive Hyprland config files
    cd ~/.config/hypr || exit 1
    mv hyprland.conf "hyprland-oldv${OLD_VERSION}.conf"
    mv hyprpaper.conf "hyprpaper-oldv${OLD_VERSION}.conf"
    mv hypridle.conf "hypridle-oldv${OLD_VERSION}.conf"

    # archive neovim config files
    cd ~/.config/nvim || exit 1
    mv init.lua "init-oldv${OLD_VERSION}.lua"
    cd ~
    echo -e "Done. -oldv${OLD_VERSION} was appended to the old config filenames."
	fi
	
  
# actually move the dotfiles to ~/.config/
read -n1 -p 'Do you want to install the dotfiles? (Y/n) ' DOTINSTALL
if [[ $DOTINSTALL == "Y" || $DOTINSTALL == "y" ]]; then

# install the hyprland dotfiles
cd ~/dotfiles
	cd hypr
	cp hyprland.conf ~/.config/hypr # The (Actual) hyprland config file  
	cp hypridle.conf  ~/.config/hypr
	cp hyprpaper.conf ~/.config/hypr

# install the neovim dotfiles
	cd ~/dotfiles
		cd ~/dotfiles/nvim
		cp init.lua ~/.config/nvim 
	cd ~/dotfiles/waybar
    cp config.jsonc ~/.config/waybar && cp style.css ~/.config/waybar
fi

cd ~
echo -e "The dotfiles are now installed, you can press super+m to restart hyprland."
