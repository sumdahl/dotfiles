#!/bin/bash

function run {
  if ! pgrep -x $(basename $1 | head -c 15) 1>/dev/null;
  then
    $@&
  fi
}


# Wallpaper #
feh --bg-fill /home/beezy/Pictures/wallpapers/nord/73.png &

# SXHKD #
run sxhkd -c ~/.config/sxhkd/sxhkdrc &


# Utility Applications #

run nm-applet &
#run pamac-tray &
run xfce4-power-manager &
numlockx on &
# blueman-applet &
#blueberry-tray &
picom --config $HOME/.config/qtile/scripts/picom.conf &
/usr/lib/xfce-polkit/xfce-polkit &
/usr/lib/xfce4/notifyd/xfce4-notifyd &
/usr/bin/dunst &


# User Applications #

run volumeicon &


