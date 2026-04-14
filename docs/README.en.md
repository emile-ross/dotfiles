# Documentation for command line arguments

[Voir cette page en francais][fr]

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

# Makefile options

The new makefile can take in a wide variety of options for compilation (whether it should treat warnings as errors, flags, compiler..)

**This compiles using the GCC compiler**

``make full``
``make gcc``

**This compiles using the ZIG CC frontend compiler**

``make base``
``make zig``

**This compiles the ``build.c`` file**
``make debug``

# Building flags

``./build`` has it's own command line flags

You can choose which flag to use for the compilation considering the warnings you want to use

These are all of the possible command line flags you can append to the ``./build`` command:

``-e`` -> append -Werror "Turn all warnings into errors" 
[source](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Werror)

``-a`` -> append -Wall "This enables all the warnings about constructions that some users consider questionable" 
[source](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall)

``-x`` -> append -Wextra "This enables some extra warning flags that are not enabled by -Wall" 
[source](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-W)

``-p`` -> append -Wpedantic "Issue all the warnings demanded by strict ISO C and ISO C++;"
[source](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1)

``-c99`` -> append -std=c99 Display all warnings from the C99 C dialect.
[source-1](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1) [source-2](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1)

see [the GCC documentation](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) for a detailed breakdown

This will compile using the following command:
```sh
zig cc build.c -o build -Wall -Wextra -pedantic
```

[fr]: README.fr.md
