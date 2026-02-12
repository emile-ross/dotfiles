## Fastfetch configuration

The ``config.jsonc`` is the configuration file that will be used by default.  
You can change this behavior by using the ``-c`` flag.

example: `` fastfetch -c ~/.config/fastfetch/config-(default).jsonc ``

--- 

The `` config.jsonc `` is the configuration I made

The `` config-(default).jsonc `` is the default configuration for fastfetch

The `` config-other.jsonc `` is a configuration file I found in [this repository](https://github.com/fastfetch-cli/fastfetch/raw/dev/doc/json_schema.json)

You can place the images or all other assets you want to use in the ``/assets`` directory

## file handling

the ``setup.c`` script allows users to change config used by fastfetch by making a link to the right file

``config.jsonc`` acts as a link instead of a normal config file

it can point to any file on the system but the ``setup.c`` script currently only lets you use the configuration files that come with this repository
