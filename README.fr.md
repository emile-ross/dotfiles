# Configuration du système
Les (dotfiles) sont des fichiers utilisés pour modifier votre système.  Vous pouvez les modifier en utilisant un éditeur de texte comme ([Neovim](https://github.com/neovim/neovim)).

[View this page in english](https://github.com/imawsumm/dotfiles)

Si vous voulez **Installer** vos configurations, cliquez [ici](#Installer)

## prérequis
- une distribution basée sur Arch Linux (Windows ne sera **jamais** supporté)
- Hyprland n'est pas nécessaire mais il est toutefois recommandé afin de bénéficier de toutes les configurations
  

## programmes modifiés
- **neovim**
  - lazy, telescope et lualine
- **hyprland**
  - avec hypridle
- **waybar**
- fastfetch
- btop
- cava
- fuzzel
- kitty
  - options de police
  - palette de couleurs
- gtklock
  - custom lockscreen background
- sway (pas complètement mis en place)
- mpv 
  - intégrer des shaders

--- 

# Installer

>  **Attention** Faites attention lorsque vous exécutez du code trouvé sur internet!

Avant d'exécuter le script en c, vous devez le compiler. 

This is a script to help new users configure their system to tbeir liking.  
You can use this script to install your dotfiles, update your dotfiles and configure your environment! 

Plus de fonctionnalités sont à venir.

```sh
cd ~
git clone https://github.com/imawsumm/dotfiles
cd dotfiles/c-scripts
gcc -c setup.c
gcc -c install.c
gcc setup.o install.o -o setup
``` 
Veuillez noter que ceci ne compile que le code nécessaire pour le script d'installation.


## Après avoir installé
Useful keybinds to know:
(super = "Windows key")
 
 super + Q -> **execute kitty**
> (the default terminal)

super + M -> **exit hyprland**

super + V -> **Toggle Floating Mode**
> ( Allows windows to stack on top of each other)

super + C -> **Close Window**


### ouvrir les applications

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
super + F1 -> **espace de travail 1**

super + shift + F1 -> **déplacer la fenètre vers l'espace de travail 1** 
 
 > *super + (F1-F11) -> espace de travail (1-11)*

ALT + Q -> **focus kitty**

ALT + 1 -> **focus floorp**

ALT + 2 -> **focus firefox**

ALT + 0 -> **focus obs**


Si jamais vous rencontrez un problème, veuillez le signaler en fournissant un "log", cela m'aide à améliorer ce script.

# Crédits

Plusieurs configurations sont inspirées directement ou indirectement de [@kzndotsh](https://github.com/kzndotsh)

AMD FSR: https://github.com/haasn/fsrcnn-mpv

(fuzzel, cava, waybar...)

Vous pouvez trouver le contenu original à: [github.com/kzndotsh/dotfiles](https://github.com/kzndotsh/dotfiles)

autres crédits:


- https://github.com/harilvfs/fastfetch
(configurations fastfetch)

- https://github.com/torvalds/linux 
(linux bien sûr)

*veulliez noter que certains crédits sont manquants*
