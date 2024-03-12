# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"
ZSH_THEME="alanpeabody"

export PATH="$PATH:/home/sumdahl/.local/bin"
export PATH="$PATH:/home/sumdahl/.flutter/bin"
export PATH="$PATH:/usr/local/bin/npm"
export EDITOR='nvim'
alias n='nvim'
alias mgsh='systemctl start mongodb'
alias python='python3'

#pacd details of package
alias pacd='pacman -Qi'
alias mand='compgen -c | fzf | xargs man'
alias pacup='sudo pacman -Syu'
alias pacob='pacman -Qdtq'
alias v='vim'
alias hehe='sudo pacman -R $(pacman -Qdtq)'
alias mpvh='mpv-handler'
alias zt='zathura'
alias rfts='rofi-theme-selector'
alias aircon='bluetoothctl connect 96:D4:08:25:39:8E'
alias aircond='bluetoothctl disconnect 96:D4:08:25:39:8E'
alias bm='bashmount'
alias bp='upower -d | grep percentage'
alias bc='upower -d | grep -i capacity'
alias fm='ranger'
alias cls='clear'
alias lg='lazygit'

plugins=(git zsh-syntax-highlighting zsh-autosuggestions)

source $ZSH/oh-my-zsh.sh


export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
eval "$(zoxide init --cmd cd zsh)"

