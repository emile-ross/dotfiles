# Configuration du système
Les (dotfiles) sont des fichiers utilisés pour modifier votre système.  Vous pouvez les modifier en utilisant un éditeur de texte comme ([Neovim](https://github.com/neovim/neovim)).

[View this page in english](https://github.com/imawsumm/dotfiles)

Si vous voulez **Installer** vos configurations, cliquez [ici](#Installer)

<table>
  <tr>
    <th>le bureau avec kitty</th>
    <!-- "desktop" -> le bureau?? l'interface generale?? -->
    <th>neovim avec telescope</th>
  </tr>
  <tr>
    <td align="center">
       <img src="assets/1.png" alt="desktop" width=400>
    </td>
    <td align="center">
      <img src="assets/2.png" alt="neovim with telescope" width=400>
    </td>
  </tr>
  <tr>
    <th>neovim</th>
    <th>fuzzel</th>
  </tr>
  <tr>
    <td align="center">
      <img src="assets/3.png" alt="neovim" width="400">
    </td>
    <td align="center">
      <img src="assets/4.png" alt="neovim" width="400">
    </td>
  </tr>
</table>


## prérequis
- une distribution basée sur Arch Linux (Windows ne sera **jamais** supporté)
- Hyprland n'est pas nécessaire mais il est toutefois recommandé afin de bénéficier de toutes les configurations
  

## programmes modifiés
- **neovim**
  - lazy, telescope et lualine
- **hyprland**
  - avec hypridle
- sway (pas complètement mis en place)
  - avec une configuration pour la «swaybar»
- **waybar**
- fastfetch
- btop
- cava
- fuzzel
- kitty
  - options de police
  - palette de couleurs
- gtklock
  - arriere plan modifié
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
git clone https://github.com/imawsumm/dotfiles
gcc dotfiles/c-scripts/setup.c dotfiles/c-scripts/functions.c dotfiles/c-scripts/install.c dotfiles/c-scripts/update.c dotfiles/c-scripts/programs.c -o setup -Wall
./setup
``` 

Veuillez noter que ceci ne compile que le code nécessaire pour le script d'installation.

## Après avoir installé
des touches utiles a connaitre:
(super = "la touche Windows")
 
 super + Q -> **execute kitty**
> (le terminal par utilisé par défaut)

super + M -> **sortir de hyprland**

super + V -> **Basculer le mode Flottant**
> (permet aux fenetres de s'empiler les unes par dessus les autres)

super + C -> **Fermer la fenêtre**


### ouvrir les applications

super + R -> **execute [fuzzel](https://codeberg.org/dnkl/fuzzel)**
> (fuzzel exécute les applications présentes sur le système)


super + E -> **execute [dolphin](https://github.com/KDE/dolphin)**
> *(un gestionnaire de fichiers avec interface graphique)*


super + 1 -> **execute [Floorp](https://github.com/Floorp-Projects/Floorp)**
> *(un navigateur web basé sur firefox/gecko)*


super + 2 -> **execute [Firefox](https://github.com/mozilla-firefox/firefox)**


super + 3 -> **execute [Chromium](https://source.chromium.org/chromium)**
> *(Chromium est google Chrome sans google (DeGoogled) )*


super + 4 -> **execute [LibreWolf](https://codeberg.org/librewolf/source)**
> *(un navigateur web basé sur firefox/gecko)*

super + 0 -> **execute [OBS](https://github.com/obsproject/obs-studio)**
> *(un programme open source permettant de diffuser et d'enregistrer des vidéos)*

## Multi Tasking
super + F1 -> **espace de travail 1**

super + MAJ + F1 -> **déplacer la fenètre vers l'espace de travail 1** 
 
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

- https://github.com/Matt-FTW/dotfiles
  (de l'art en symboles ASCII)

*veulliez noter que certains crédits sont manquants*
