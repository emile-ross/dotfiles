# Command line flags 

## --version

The ``--version`` or ``-v`` flag outputs the dotfile's version

## --help

Display the help menu

## --noconfirm

The ``--noconfirm`` flag installs everything (every program and every configuration) without any prompts.

## -i

The ``-i`` flag displays information about a configuration.  
Append the configuration name to the end of your command like this:

The "hypr" package is specified meaning [Hyprland](https://hypr.land/)

``./setup -i hypr``

## -p

The ``-p`` flag installs the specified package using the appropriate package manager.

It's package manager choice is based on the contents of the ``/etc/os-release`` file.

The "nvim" package is specified meaning [NeoVim](https://hypr.land/)

``./setup -p nvim``
