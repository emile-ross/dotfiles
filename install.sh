#! /usr/bin/bash

# check if yay is installed
cd ~
ISYAY=/sbin/yay
if [ -f $ISYAY ] ; then

echo -e " Yay is nstalled, congrats \n"

else
   # install yay if it isn't already installed
   read -n1 -p "Yay is not installed, do you want to install it? (Y/n): " YAY
   if [[ $YAY == "Y" || $YAY == "y" ]]; then
   # install yay since it is needed to install the dependencies
   
      # check if makepkg is installed
      if ! command -v makepkg &>/dev/null; then
      echo -e "\nmakepkg is not installed. Installing 'base-devel' package group to proceed...\n"
      sudo pacman -S --noconfirm base-devel
	  
      # Check if makepkg is available after installing base-devel
      if ! command -v makepkg &>/dev/null; then
        echo -e "makepkg installation failed. Please check your system configuration.\n"
        exit 1
      else
        echo -e "makepkg has been successfully installed!\n"
	  fi
    else
      echo -e "makepkg is already installed.\n"
    fi
   git clone https://aur.archlinux.org/yay.git
   cd yay
   makepkg -si
   cd ..
   echo -e "\nYay is nstalled, congrats!"

   else
      echo -e "\nYay is needed in order to proceed with the script"
      exit 1
   fi
fi

# install dependencies
read -n1 -p 'Do you want to proceed with the installation of packages? (Y/n) ' PKGINSTALL
if [[ $PKGINSTALL == "Y" || $PKGINSTALL == "y" ]]; then
	yay -S --noconfirm hyprland kitty waybar gtklock hyprpaper wofi
fi
# actually install the dotfiles
read -n1 -p 'Do you want to install the dotfiles? (Y/n) ' DOTINSTALL
if [[ $DOTINSTALL == "Y" || $DOTINSTALL == "y" ]]; then
cd ~
cp hypr ~/.config/
cp nvim ~/.config/
fi

cd ~
