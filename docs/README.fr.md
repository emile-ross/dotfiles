# Documentation pour les options sur la ligne de commande

[View this page in english][en]

## Cette traduction est incomplète
La version en anglais est plus claire, complète et précise.
## Aide 
### ``--help``

Aficher le menu d'aide. 

**Ceci compile en utilisant GCC**

``make full``
``make gcc``

**Ceci compile en utilisant ZIG CC**

``make base``
``make zig``

# Options de compilation

La commande ``./build`` dispose de ses propres options de ligne de commande

Vous pouvez choisir l'option à utiliser pour la compilation en fonction des avertissements ou des erreurs que vous souhaitez voir

Voici tous les arguments de ligne de commande que vous pouvez ajouter suite à la commande ``./build`` :

``-e`` -> ajoute ``-Werror`` à la fin de la commande (Traite les avertissements comme si ils étaient des erreurs) 

source: [https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Werror](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Werror)

``-a`` -> ajoute ``-Wall`` à la fin de la commande (Cet étiquette active tous les avertissements concernant les constructions que certains utilisateurs considèrent douteux)

source: [https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall)

``-x`` -> ajoute -Wextra à la fin de la commande 

source: [https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-W](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-W)

``-p`` -> append -Wpedantic "Issue all the warnings demanded by strict ISO C and ISO C++;"

source: [https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1)

``-c99`` -> append -std=c99 Display all warnings from the C99 C dialect.

sources: 
[https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1)
[https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-pedantic-1)

  voir [la documentation de GCC](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) pour obtenir une explication détaillée de ce programme


[en]: README.en.md
