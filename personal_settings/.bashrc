
##########################################################################################################################
# dolev's script
##########################################################################################################################

export USE_GKE_GCLOUD_AUTH_PLUGIN=True

alias a='--ask-pass' #for ansible cli

alias gcl='gcloud auth application-default login'
alias tf='terraform'
alias ti='tf init'
alias tp='tf plan'
alias ta='tf apply -auto-approve'
alias td='tf destroy -auto-approve'

# alias cnf='code \\wsl$\Ubuntu-20.04\home\darev\.bashrc'
alias des='cd /mnt/c/Users/darev/Desktop'
alias gua='cd /mnt/c/Users/darev/Desktop/git/guardicore'
alias dev='cd /mnt/c/Users/darev/Desktop/git/devops'
alias pro='cd /mnt/c/Users/darev/Desktop/git'
alias mys='cd /mnt/c/Users/darev/Desktop/git/my_scripts'
alias bot='cd /mnt/c/Users/darev/Desktop/git/bots'
alias guc='cd /mnt/c/Users/darev/Desktop/git/guardicore_cloud'

alias s='source'
alias sv='s venv/bin/activate'
alias ipy3="python3 -c 'import IPython; IPython.terminal.ipapp.launch_new_instance()'"
alias ipy2="python2 -c 'import IPython; IPython.terminal.ipapp.launch_new_instance()'"
alias ipy='ipy3'

alias ga='git add'
alias gc='git commit -m'
alias gp='git push -u origin HEAD'
alias gpf='gp -f'
alias gco='git checkout -q'
alias grmb='git branch -D'
alias grmbr='git push origin --delete'
alias gcbn='git branch -m'
alias grh='git reset --hard'
alias gca='git commit --amend -m'
alias gcallowe="git commit --allow-empty -m 'empty'"
alias gnbne="git checkout -b"

alias gs='git status'
alias gpb='git push -u origin'
alias gpull='git pull origin -q'
alias gb='git branch'
alias gbl='git branch'
alias gl='git branch'
alias glog='git log'
alias gdb='git branch -dq'
alias gchp='git cherry-pick'
alias gchpc='git cherry-pick --continue'

alias reload='source ~/.bashrc'
alias evenv='source venv/bin/activate'

# for servers

#COOL TRICKS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
alias ipt='iptables -t nat -nvL' #show all ports
alias pap='netstat -o -a' #show process and ports for them
alias seli='systemctl list-units --type=service' #show all the services
# !!!!!!!!!!!!!!!!!!
alias rmsn='find -name dolev\* |xargs rm -fr'

alias gci='sudo gc-image-shell'
alias ls='ls --color=always'
alias grep='grep --color=always'
alias fgrep='fgrep --color=always'
alias egrep='egrep --color=always'
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'
alias c="clear && printf '\e[3J'"
alias p='python'
alias p3='python3'
alias p2='python2'
alias cb='cd ..' 
alias python='p3'
alias h='history'

alias j='java'
alias jc='javac'
# touch ~/.vimrc
# echo 'syntax on' > .vimrc

# end for servers
function getb(){
    gl |grep $1
}

function geth(){
    h |grep $1
}

function gacp(){
    ga .
    gc "$1"
    gp
}

function gacap(){
    ga .
    gca "$1"
    gpf
}

function greb(){
    git fetch origin $1:$1
    git rebase $1
}

function grebm(){
    git fetch origin master:master
    git rebase master
}

function gresetm(){
    gcom
    git fetch origin
    git reset --hard origin/master
}

function greset(){
    gcom
    git fetch origin
    git reset --hard origin/$1
}

function grebc(){
    git rebase --continue
}

function gcom(){
git checkout -q master
gpull
}

function gnb(){
git checkout -b $1
gcallowe
}

function gnbm(){
gcom
gnb $1
}

# function gcallowep(){
# gcallowe
# gp
# }

function gmbm(){
git reset --hard master
}

function sk(){
    sudo ssh-keygen -t rsa -f ~/.ssh/$1 -C $USER
    cd ~/.ssh
    chmod 400 $1
    sudo cat $1.pub
}

function skr(){
    sudo ssh-keygen -t rsa -f ~/.ssh/$1 -C root
    cd ~/.ssh
    chmod 400 $1
    sudo cat $1.pub
}

function si(){
    ssh -i $1 $USER@$2
}

function venv2(){
    virtualenv -p python2 venv
    source venv/bin/activate
}

function venv3(){
    python3 -m venv venv
    source venv/bin/activate
}

# adding paths to python
export PYTHONPATH="${PYTHONPATH}:/mnt/c/Users/darev/Desktop/git"
export PYTHONPATH="${PYTHONPATH}:/mnt/c/Users/darev/Desktop/git/guardicore"

# adding paths to go
export GOROOT=/usr/local/go-1.18
export GOPATH=$HOME/go
export PATH=$GOPATH/bin:$GOROOT/bin:$PATH

# for terraform auto complete
complete -o nospace -C /usr/local/bin/terraform terraform

# getting the git in the right of terminal
# for bash
parse_git_branch() {
     git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}
export PS1="\u@\h \[\e[32m\]\w \[\e[91m\]\$(parse_git_branch)\[\e[00m\]$ "
# for mac
# dolev2
# parse_git_branch() {
#     git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
# }
# setopt PROMPT_SUBST
# PROMPT='%9c%{%F{green}%}$(parse_git_branch)%{%F{none}%} $ '

# The next line updates PATH for the Google Cloud SDK.
if [ -f '/Users/darev/google-cloud-sdk/path.zsh.inc' ]; then . '/Users/darev/google-cloud-sdk/path.zsh.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/Users/darev/google-cloud-sdk/completion.zsh.inc' ]; then . '/Users/darev/google-cloud-sdk/completion.zsh.inc'; fi

# end of my bashrc (dolev)

# getting the git in the right of terminal
# for bash
parse_git_branch() {
     git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}
export PS1="\u@\h \[\e[32m\]\w \[\e[91m\]\$(parse_git_branch)\[\e[00m\]$ "

export LINODE_ACCESS_KEY="JATHQOGFKP18IEJ0C0ZC"
export LINODE_SECRET_KEY="Di62Lp3QqCoPJBngJNHnISYBT9z7KrRAse27EaTv"
export LINODE_TOKEN="23e490b60a5436d1e09331966d4ee50cd3e75a2e8745c2cf22c273b3fa53e5f4"
