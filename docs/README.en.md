# Documentation for command line arguments

## apply a config
### ``-c``

Will install the specified config along with the package

Note: the ``-c`` flag does not install the packages needed for the config.  If you want to install the package use ``-p``.  

## help 
### ``--help``

Display help menu

## display information about a package
### ``-i``

This will display a basic description for the specified package


## install everything
### ``--noconfirm``

Proceed with the full installation of the dotfiles without any confirmations or warnings.  

```bash
./setup --noconfirm
```

This will not give any choices to the user.  It should only be used if the operating system was recently installed or if the user doesn't care about their existing configurations.  

## install a package
### ``-p``

Install a package using the method appropriate for the distro

## features

Display a short description of the specified package using the ``-i`` flag

Install the specified config along with the package ``-c``
