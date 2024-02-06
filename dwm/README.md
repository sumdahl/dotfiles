dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:


    while type dwm >/dev/null; do dwm && continue || break; done 

(_This won't kill apps while restarting dwm_)

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm

or

try something like [slstatus](https://tools.suckless.org/slstatus/). 

Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.


Some Info
------------
- The modkey is the metakey.
- This build uses scripts to control brightness checkout *config.h* and for *scripts* [here](https://github.com/razzat008/dotfiles).
- *[st](https://st.suckless.org)* terminal is the default terminal.

Patches Applied
------------
These are the patches that I have applied on this build of dwm.
- systray: shows icon of the active daemons
- awesomebar: enables hiding of different applications and switching between them
- centeredmaster: just an layout which always puts master at the center
- fibonacci: layout that is similar to the fibonacci pattern
- preserveonrestart: attaches clients to the tags they were opened on while restarting dwm
- pertag: changing layout on one tag doesn't affect other tags
- fullgaps: gapps between windows
- hide_vacant_tags: hides tags with no client/applications in them
- autostart: to put stuff you'd put in .xinitrc
