# slstatus - suckless status

slstatus is a suckless status monitor for window managers that use WM_NAME
(e.g. dwm) or stdin to fill the status bar.

## Features

- Battery percentage/state/time left
- CPU usage
- CPU frequency
- Custom shell commands
- Date and time
- Disk status (free storage, percentage, total storage and used storage)
- Available entropy
- Username/GID/UID
- Hostname
- IP address (IPv4 and IPv6)
- Kernel version
- Keyboard indicators
- Keymap
- Load average
- Network speeds (RX and TX)
- Number of files in a directory (hint: Maildir)
- Memory status (free memory, percentage, total memory and used memory)
- Swap status (free swap, percentage, total swap and used swap)
- Temperature
- Uptime
- Volume percentage
- WiFi signal percentage and ESSID

## Requirements

Currently slstatus works on FreeBSD, Linux and OpenBSD.
In order to build slstatus you need the Xlib header files.

## Installation

Edit config.mk to match your local setup (slstatus is installed into the
/usr/local namespace by default).

Afterwards enter the following command to build and install slstatus (if
necessary as root):

    make clean install

## Running slstatus

I run it with .xinitrc.

`exec slstatus &` 

To tryout the new config.

`killall slstatus`

`slstatus &disown`

## Configuration

slstatus can be customized by creating a custom config.h and (re)compiling the
source code. This keeps it fast, secure and simple.

### This is what it looks like with simple editing.

This configuration is in config.def.h remove config.h to get what you're seeing below.

![image](https://github.com/razzat008/slstatus/assets/93041325/b27daa6a-4bc9-4571-b523-5e9d3a703fe1)

### WARNING

 You'd need status2d patch for dwm to be able to use this build.
 Head over to my [dwm](https://github.com/razzat008/dwm/) repo to get a fully customized dwm build. 
