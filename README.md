# ImAwsum's dotfiles
Dotfiles are files used to customize your system to your liking.  You can modify them to your liking by editing them using a text editor.  
Click [here](#install) to install 

## requirements
- an Arch based distribution of linux (Windows will **never** get support)
- Hyprland isn't required but still recomended in order to benefit from all configurations
  

## programs modified
- neovim
- hyprland
- waybar
- gtklock
- *fastfetch ( not yet)*
- *kitty (not yet)*
  
- *Firefox* (not yet)
- *LibreWolf* (not yet)


## install

note: this script is still unfinished and you **will** encounter bugs
bash script:
```sh
git clone https://github.com/ImAwsumm/dotfiles.git
cd dotfiles
chmod u+x ./install.sh
chmod u+x ./update.sh
./install.sh
```
before executing the c script, you will need to compile it.  
```bash
git clone https://github.com/ImAwsumm/dotfiles.git
gcc install-script.c -o cinstall
./cinstall
```
A new install script is in the making.  It will run faster because it is in C instead of bash.  This script will need to be compiled using the gcc compiler.

## after install 
Useful keybinds to know:
(super = "Windows key")
 
 super + q -> **execute Kitty**
 super + 1 -> **execute LibreWolf**
 super + 2 -> **execute Firefox**
 
 
 super + F1 -> **switch to Workspace 1**
 
 (super + F1-F10 -> Workspaces 1-10)

 super + m -> **exit hyprland**

If you ever encounter an issue please report it by providing the issue you are experiencing with a log, it helps me improve this script. 
