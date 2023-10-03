#!/bin/bash

xset r rate 300 40
picom --config $HOME/.config/picom/picom.conf --vsync &

# map caps lock button as escape button
setxkbmap -option caps:escape_shifted_capslock
#but when it is pressed once, treat it as escape
killall xcape 2>/dev/null ; xcape -e 'Caps_Lock=Escape'

# flameshot 
exec flameshot &

#locker
locker &

#status bars for dwm
exec slstatus &

#policykit gui
if [[ "$(pidof xfce-polkit)" ]]; then
  echo " xfce4-polkit is running"
else
  echo "starting xfce-polkit"
  exec /usr/lib/xfce-polkit/xfce-polkit &
fi

#for wallpaper
# nitrogen --restore --set-scaled &
if [[ $(pidof nitrogen) ]]; then
  echo "nitrogen is running"
else
  echo "starting"
  exec nitrogen --restore --set-scaled &
fi

# MPD daemon start (if no other user instance exists)
[ ! -s ~/.config/mpd/pid ] && mpd
if [[ "$(pidof mpd)" ]]; then
  echo "mpd is running"
else
  echo "starting mpd daemon"
  exec mpd &
fi

#to start kdeconnect daemon and indicator
/usr/lib/kdeconnectd &
# kdeconnect-indicator &

