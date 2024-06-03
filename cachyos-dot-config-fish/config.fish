source /usr/share/cachyos-fish-config/cachyos-config.fish

# overwrite greeting
# potentially disabling fastfetch
#function fish_greeting
#    # smth smth
#end

# bun
set --export BUN_INSTALL "$HOME/.bun"
set --export PATH $BUN_INSTALL/bin $PATH
set -gx EDITOR "nvim"

if test "$XDG_SESSION_TYPE" = "wayland"
    set -x MOZ_ENABLE_WAYLAND 1
end


# pnpm
set -gx PNPM_HOME "/home/sumdahl/.local/share/pnpm"
if not string match -q -- $PNPM_HOME $PATH
  set -gx PATH "$PNPM_HOME" $PATH
end
# pnpm end
