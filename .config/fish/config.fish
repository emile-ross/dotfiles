# Commands to run in interactive sessions can go here
if status is-interactive
    # No greeting
    set fish_greeting

    # Use starship
    function starship_transient_prompt_func
        starship module character
    end
    if test "$TERM" != "linux"
        starship init fish | source
        enable_transience
    end
    
    # Colors
    if test -f ~/.local/state/quickshell/user/generated/terminal/sequences.txt
        cat ~/.local/state/quickshell/user/generated/terminal/sequences.txt
    end

    # Aliases
    # kitty doesn't clear properly so we need to do this weird printing
    alias clear "printf '\033[2J\033[3J\033[1;1H'"
    alias celar "printf '\033[2J\033[3J\033[1;1H'"
    alias claer "printf '\033[2J\033[3J\033[1;1H'"
    alias pap 'mpvpaper ALL -o "no-audio" ~/Videos/bg.mp4'
    alias pamcan pacman
    alias yya yay
    alias l 'eza --icons=auto -A'
    alias swayconf 'nvim ~/.config/sway/config'
    alias wininit 'htop'
    alias codeberg 'ln -sf ~/.gitconfig-codeberg ~/.gitconfig'
    alias github 'ln -sf ~/.gitconfig-github ~/.gitconfig'
    alias nvim-swap '~/scripts/swap_nvim.sh'
    alias shut='systemctl poweroff'
    alias pls sudo
    alias q 'qs -c ii'
    if test "$TERM" = "xterm-kitty"
        alias ssh 'kitten ssh'
    end
end
