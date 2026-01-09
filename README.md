# ImAwsum's dotfiles
Dotfiles are files used to customize your system to your liking.  You can modify them by editing config files using a text editor ([Neovim](https://github.com/neovim/neovim)).


If you want to **install** your dotfiles, click [here](#install) 
If you want to **update** your dotfiles, click [here](#Update)

## requirements
- an Arch based distribution of linux (Windows will **never** get support)
- Hyprland isn't required but still recomended in order to benefit from all configurations
  

## programs modified
- neovim
  - lazy, telescope and lualine
- hyprland
- waybar
- fastfetch
- cava
- fuzzel
- kitty
  - font options
  
- *Firefox* (not planned)
- *LibreWolf* (not planned)
- *Floorp* (not planned)
- *Chromium* (not planned)
- *gtklock* (not yet)
--- 

## Install

In order to install the dotfiles you will need to run a C script.  

>  **Warning** Be careful running scripts found on the internet!

Before executing the c script, you will need to compile it.  
```bash
git clone https://github.com/ImAwsumm/dotfiles.git
cd dotfiles/c-scripts
gcc install.c -o cinstall
./cinstall
```

## after install 
Useful keybinds to know:
(super = "Windows key")
 
 > super + Q -> **execute kitty**

 > super + R -> **execute fuzzer**

 > super + 1 -> **execute floorp**
 
 > super + 2 -> **execute firefox**

 > super + 3 -> **execute LibreWolf**
 
 > super + F1 -> **switch to Workspace 1**
 
 > *super + (F1-F11) -> Workspaces (1-11)*

 > super + m -> **exit hyprland**

If you ever encounter an issue please report it by providing the issue you are experiencing with a log, it helps me improve this script. 

# Update

After reading the code, you can paste this in your terminal in order to update.  
This will download the latest script from this github and it will then execute the newest updating script.

```sh 
cd ~/dotfiles/c-scripts
gcc new-update.c -o update
./update
```
# Credits 

Many configs were directly from or inspired by [@kzndotsh](https://github.com/kzndotsh)

(fuzzel, cava, waybar...)

You can find the original content at: [github.com/kzndotsh/dotfiles](https://github.com/kzndotsh/dotfiles)
