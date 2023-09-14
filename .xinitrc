systemctl --use import-environment DISPLAY

setxkbmap -option caps:escape_shifted_capslock

picom --config $HOME/.config/qtile/scripts/picom.conf &

nitrogen --restore --set-scaled &

killall xcape 2>/dev/null ; xcape -e 'Caps_Lock=Escape'

xset r rate 400 40 


#if [[ $(pidof qtile) ]]; then
#  echo ""
# else
#    echo " starting qtile"
qtile start
#fi

sxhkd -c /home/sumdahl/.config/sxhkd/sxhkdrc &

#policykit gui
# polit_exec=/usr/lib/xfce-polkit/xfce-polkit
# exec /usr/lib/xfce-polkit/xfce-polkit &
if [[ "$(pidof xfce-polkit)" ]]; then
  echo " xfce4-polkit is running"
else
  echo "starting xfce-polkit"
  exec /usr/lib/xfce-polkit/xfce-polkit &
fi


# run flameshot daemon
if [[ "$(pidof flameshot)" ]]; then
  echo " flameshot is running"
else
  echo "starting flameshot"
  exec flameshot &
fi
