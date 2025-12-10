#! /usr/bin/bash

# check if yay is installed

$ISYAY=/sbin/yay

if [ -f $ISYAY ] ; then
echo -e " Yay is nstalled, congrats \n"
else 
# install yay if it isn't already installed

echo -e "Yay is not installed, do you want to install it? \n"
read -n1 '(Y/n)' YAY
if [[ $YAY == "Y" || $YAY == "y" ]]; then
# install yay since it is needed to install the dependencies
   git clone https://aur.archlinux.org/yay.git
   cd yay
   makepkg -si
fi

# install dependencies
read -n1 -p 'Do you want to proceed with the installation of packages the packages? (Y/n)'
yay -S --noconfirm hyprland kitty waybar gtklock hyprpaper wofi

# actuallt install the dotfiles
