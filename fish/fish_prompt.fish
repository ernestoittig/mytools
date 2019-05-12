function fish_prompt --description 'Write out the prompt'
    set lasts $status
    set -q __fish_git_prompt_showupstream
    or set -g __fish_git_prompt_showupstream auto

    function _prompt_wrapper
        set wcol $argv[1]
        set name $argv[2]
        set value $argv[3]

        set_color normal
        set_color $wcol
        echo -n '─'
        set_color -o green
        echo -n '['
        set_color normal
        test -n $name
        and echo -n $name:
        set_color $wcol
        echo -n $value
        set_color -o green
        echo -n ']'
    end
    and set wcol green
    or set wcol red

    set_color $wcol
    echo -n ┬─
    set_color -o green
    echo -n [
    switch "$USER"
        case root toor
            set prefix '#'
			set_color -o red
        case '*'
            set prefix '$'
            set_color -o green
    end
    echo -n $USER
    set_color -o white
    echo -n @
    if [ -z "$SSH_CLIENT" ]
        set_color -o blue
    else
        set_color -o cyan
    end
    echo -n (prompt_hostname)
    set_color -o white
    echo -n ' in' (prompt_pwd)
    set_color -o green
    echo -n ']'

    # Día
    _prompt_wrapper $wcol '' (date +%d/%m/%y)

    # git
    set prompt_git (__fish_git_prompt | string trim -c ' ()')
    test -n "$prompt_git"
    and _prompt_wrapper $wcol G $prompt_git

    #exit code
    test $lasts -ne 0
    and _prompt_wrapper $wcol EC $lasts

    #new line
    echo
    
    
    set_color normal
    set_color $wcol
    echo -n '╰─>'
    set_color -o red
    echo -n "$prefix "
    set_color normal
    #echo -sn ┬─ (sqet_color $color_user) "[$USER" (set_color $fish_color_at) @ (set_color $fish_color_host) (prompt_hostname) ' ' (set_color $color_cwd) (prompt_pwd) \] " "\u001b\[38\;5\;202m(parse_git_branch) 
    #if [ $status -ne 0 ]
        #echo (set_color white -o -b red) $status
        #else
        #echo
        #end
    #echo -sn (set_color normal) "$suffix "
end
