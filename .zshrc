autoload -U compinit && compinit
export MAIL=dsouleym@student.42.fr
export USER=dsouleym
zstyle ':completion:*' matcher-list 'm:{a-zA-Z}={A-Za-z}'
PROMPT="> " RPROMPT="%T"
alias cd..='cd ..;clear'
alias norminette='clear;norminette'
alias -g gccw='clear;gcc -Wall -Wextra -Werror'
alias 42FileChecker='sh ~/42FileChecker/42FileChecker.sh'
alias ll='ls -l'
test -e "${HOME}/.iterm2_shell_integration.zsh" && source "${HOME}/.iterm2_shell_integration.zsh"
alias valgrind="~/.brew/bin/valgrind"
# Load Homebrew config script
source $HOME/.brewconfig.zsh
