#!/bin/bash

function run {
  if ! pgrep -x $(basename $1 | head -c 15) 1>/dev/null;
  then
    $@&
  fi
}

# Wallpaper #
nitrogen --restore --set-scaled &

#mpd daemon
mpd &
# SXHKD #
run sxhkd -c ~/.config/sxhkd/sxhkdrc &

#extra esc
setxkbmap -option caps:escape_shifted_capslock
killall xcape 2>/dev/null ; xcape -e 'Caps_Lock=Escape'
xset r rate 400 40 

# Utility Applications #
run nm-applet &
numlockx on &
flameshot &
#picom config
picom --config $HOME/.config/qtile/scripts/picom.conf &

#xfce-polkit
/usr/lib/xfce-polkit/xfce-polkit &
/usr/lib/xfce4/notifyd/xfce4-notifyd &
#dunst notifier
/usr/bin/dunst &

#kdeconnect
/usr/lib/kdeconnectd &
#kde connect indicator
kdeconnect-indicator & 

# User Applications #
run volumeicon &


