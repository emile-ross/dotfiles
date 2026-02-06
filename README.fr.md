# Configuration du système
Dotfiles are files used to customize your system to your liking.  You can modify them by editing config files using a text editor ([Neovim](https://github.com/neovim/neovim)).

[Voir cette page en francais][fr]

Si vous voulez **Installer** vos configurations, cliquez [ici](#Installer)

## prérequis
- une distribution basée sur Arch Linux (Windows ne sera **jamais** supporté)
- Hyprland n'est pas nécessaire mais il est toutefois recommandé afin de bénéficier de toutes les configurations
  

## programs modified
- **neovim**
  - lazy, telescope and lualine
- **hyprland**
  - with hypridle
- **waybar**
- fastfetch
- btop
- cava
- fuzzel
- kitty
  - font options
  - color scheme
- gtklock
  - custom lockscreen background
- sway (not fully implemented)
- mpv

--- 

## Installer

>  **Attention** Be careful running scripts found on the internet!

Before executing the c script, you will need to compile it.  

This is a script to help new users configure their system to tbeir liking.  
You can use this script to install your dotfiles, update your dotfiles and configure your environment! 

More features will come in the future

```sh
git clone https://github.com/imawsumm/dotfiles
gcc dotfiles/c-scripts/setup.c -o dotfiles/setup
./dotfiles/setup
``` 
note: This only compiles the code necessary for the install script. 


## after install 
Useful keybinds to know:
(super = "Windows key")
 
 super + Q -> **execute kitty**
> (the default terminal)

super + M -> **exit hyprland**

super + V -> **Toggle Floating Mode**
> ( Allows windows to stack on top of each other)

super + C -> **Close Window**


### execute programs

super + R -> **execute [fuzzel](https://codeberg.org/dnkl/fuzzel)**
> (fuzzel is the app launcher)


super + E -> **execute [dolphin](https://github.com/KDE/dolphin)**
> *(A gui file manager)*


super + 1 -> **execute [Floorp](https://github.com/Floorp-Projects/Floorp)**
> *(firefox/gecko based web browser)*


super + 2 -> **execute [Firefox](https://github.com/mozilla-firefox/firefox)**


super + 3 -> **execute [Chromium](https://source.chromium.org/chromium)**
> *(Chromium is a DeGoogled Chromium browser)*


super + 4 -> **execute [LibreWolf](https://codeberg.org/librewolf/source)**
> *(firefox/gecko based web browser)*

super + 0 -> **execute [OBS](https://github.com/obsproject/obs-studio)**
> *(an open source program to stream and record videos)*

## Multi Tasking
super + F1 -> **switch to Workspace 1**

super + shift + F1 -> **move window to Workspace 1** 
 
 > *super + (F1-F11) -> Workspaces (1-11)*

ALT + Q -> **focus kitty**

ALT + 1 -> **focus floorp**

ALT + 2 -> **focus firefox**

ALT + 0 -> **focus obs**


If you ever encounter an issue please report it by providing the issue you are experiencing with a log, it helps me improve this script. 

# Credits 

Many configs were directly from or inspired by [@kzndotsh](https://github.com/kzndotsh)

amd fsr: https://github.com/haasn/fsrcnn-mpv

(fuzzel, cava, waybar...)

You can find the original content at: [github.com/kzndotsh/dotfiles](https://github.com/kzndotsh/dotfiles)

other credits:

- https://github.com/harilvfs/fastfetch
(fastfetch config)

- https://github.com/torvalds/linux 
(linux bien sûr)

*veulliez noter que certains crédits sont manquants*


[fr]: README.fr.md
