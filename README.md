# ImAwsum's dotfiles
Dotfiles are files used to customize your system to your liking.  You can modify them to your liking by editing them using a text editor.  
Click [here](#install) to install 

If you want to update your dotfiles, click [here](#Update)

## requirements
- an Arch based distribution of linux (Windows will **never** get support)
- Hyprland isn't required but still recomended in order to benefit from all configurations
  

## programs modified
- neovim
- hyprland
- waybar
- gtklock
- fastfetch


- *kitty* (not yet)
- *Firefox* (not planned)
- *LibreWolf* (not planned)
- *Floorp* (not planned)
- *Chromium* (not planned)

--- 

## Install

In order to install the dotfiles you will need to run a C script.  

>  **Warning** Be careful running scripts found on the internet!

Before executing the c script, you will need to compile it.  
```bash
git clone https://github.com/ImAwsumm/dotfiles.git
gcc install.c -o cinstall
./cinstall
```
A new install script is in the making.  It will run faster because it is in C instead of bash.  This script will need to be compiled using the gcc compiler.

## after install 
Useful keybinds to know:
(super = "Windows key")
 
 super + q -> **execute Kitty**
 super + 1 -> **execute Floorp**
 super + 2 -> **execute Firefox**
 super + 3 -> **execute LibreWolf**
 
 super + F1 -> **switch to Workspace 1**
 
 (super + F1-F10 -> Workspaces 1-10)

 super + m -> **exit hyprland**

If you ever encounter an issue please report it by providing the issue you are experiencing with a log, it helps me improve this script. 

# Update

After reading the code, you can paste this in your terminal in order to update

```sh 
cd ~/dotfiles/c-scripts
gcc update.c -o update
./update
```
