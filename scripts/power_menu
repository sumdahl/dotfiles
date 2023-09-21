#!/bin/bash

# script to act as powermenu for dmenu
DMENU='dmenu -i -fn Iosevka:size=10 -nb #222222 -nf #fff -sb #83bae8 -sf #000000'
choice=$(echo -e "logout\nshutdown\nreboot\nsuspend\nhibernate" | $DMENU)

case "$choice" in
  logout) loginctl terminate-user $USER  & ;;
  shutdown)  shutdown -h now & ;;
  reboot) reboot  & ;;
  suspend) systemctl suspend & ;;
  hibernate) systemctl hibernate & ;;
esac
