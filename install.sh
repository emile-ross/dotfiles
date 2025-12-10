#! /usr/bin/bash

# check if yay is installed

$ISYAY=/sbin/yay

if [ -f $ISYAY ] ; then
echo -e " Yay is nstalled, congrats \n"
else 
# yay is not installed 
echo -e " yay is not installed, do you want to install it"
read -n1 '(Y/n)' YAY
if [[ $YAY == "Y" || $YAY == "y" ]]; then
git clone https://aur,archlinux.org/yay.git
cd yay
makepkg -si
fi


# install dependencies
yay -S --noconfirm hyprland kitty waybar gtklock
