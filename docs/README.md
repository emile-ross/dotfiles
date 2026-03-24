# Documentation for command line arguments

## description for a package
### ``-d``

Provides a short description for the specified package


## full install
### ``--noconfirm``

Proceed with the full installation of the dotfiles without any confirmations or warnings.  

```bash
./setup --noconfirm
```

## apply a config
### ``-c``

Will install the specified config along with the package

Note: the ``-c`` flag does not install the packages needed for the config.  If you want to install the package use ``-p``. 


## install a package
### ``-p``

Install a package using the method appropriate for the distro


Display help menu
``--help``


## display information about a package
### ``-i``

This will display a basic description for the specified package

## features

Display a short description of the specified package using the ``-i``
