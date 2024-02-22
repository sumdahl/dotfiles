/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char dmenufont[] = "JetBrainsMono NF:size=11";
static const char *fonts[] = {"JetBrainsMono NF:style:medium:size=11", "JetBrainsMono NF:style:medium:size=9", "Material Design Icons Desktop:size=9"};
static const char col_gray1[] = "#222222"; // backgroud colour normally seen
static const char col_gray2[] = "#E8B082"; // border for unfocused window
static const char col_gray3[] = "#fff";    // font color ;normal
static const char col_gray4[] = "#000000"; // font color when focused on a window
// static const char col_cyan[] = "#E8B082";  // border color when the window is focused
// static const char col_cyan[] = "#83bae8";  // border color when the window is focused
static const char col_active[] = "#83bae8";
static const char col_cyan[] = "#ABE9B3";  // border color when the window is focused
                                           //this is the default color #83bae8

static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1,   col_gray2},
    [SchemeSel] =  {col_gray4, col_cyan,    col_active},
    [SchemeHid] =  {col_cyan,  col_gray1,   col_cyan},
};

/* tagging */

static const char *tags[] = {"",  "",  "3", "", "󰙯",
                             "󰓇", " ", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    // {"Gimp",      NULL,       NULL,           0,        0,           -1},
    // {"neovide",   NULL,       NULL,       1 <<2  ,      0,           -1 },
    {"Thorium-browser", NULL, NULL, 1 << 1, 0, -1},
    {"ViberPC", NULL, NULL, 1 << 2, 0, -1},
    // {"Signal",       NULL,       NULL,       1 <<3  ,      0,           -1 },
    {"discord", NULL, NULL, 1 << 4, 0, -1},
    {"thunderbird", NULL, NULL, 1 << 6, 0, -1},

    /* class            instance    title       tags mask     isfloating monitor
     */
    {"Nitrogen", NULL, NULL, 0, 1, -1},
    {"Pavucontrol", NULL, NULL, 0, 1, -1},
    // {"Gscreenshot",     NULL,       NULL,       0,                1, -1},
    {"Spotify", NULL, NULL, 1 << 5, 0, -1},
    {"TelegramDesktop", NULL, NULL, 1 << 3, 0, -1},
    {"Element", NULL, NULL, 1 << 3, 0, -1},

};
/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define altkey Mod1Mask
#define space 0x20
#define printsc 0xff61
#define brightup 0xffc9
#define brightdown 0xffc8
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb",
col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
  // custom keybindings start {start}
    // raise volume
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("~/.local/bin/volume up")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("~/.local/bin/volume down")},
    {0, XF86XK_AudioMute, spawn, SHCMD("~/.local/bin/volume mute")},
    {0, XF86XK_RFKill, spawn, SHCMD("rfkill toggle all")},

    // change media controls
    {0, XF86XK_AudioPlay, spawn, SHCMD("~/.local/bin/MediaControl --toggle")},
    {0, XF86XK_AudioPrev, spawn, SHCMD("~/.local/bin/MediaControl --previous")},
    {0, XF86XK_AudioNext, spawn, SHCMD("~/.local/bin/MediaControl --next")},
    {0, XF86XK_AudioStop, spawn, SHCMD("~/.local/bin/MediaControl --stop")},

    // to take screenshot from flame shot

    {0, printsc, spawn, SHCMD("flameshot gui")},
    {MODKEY, printsc, spawn, SHCMD("flameshot full")},
    //
    {MODKEY | ShiftMask, XK_p, spawn, SHCMD("~/.local/bin/power_menu")},
    // to control brightness
    //  {0, XF86XK_MonBrightnessUp,         spawn,
    //  SHCMD("~/.local/bin/ChangeBrightnes up")}, {0, XF86XK_MonBrightnessDown,
    //  spawn, SHCMD("~/.local/bin/ChangeBrightnes down")},
    {altkey, XK_Up, spawn, SHCMD("bash ~/.local/bin/ChangeBrightness up")},
    {altkey, XK_Down, spawn, SHCMD("bash ~/.local/bin/ChangeBrightness down")},

    // custom keybindings to Launch applications/programs
    {MODKEY, XK_n, spawn, SHCMD("thunar")},
    {altkey, XK_f, spawn, SHCMD("librewolf")},
    {altkey, XK_b, spawn, SHCMD("thorium-browser")},
    {altkey, XK_t, spawn, SHCMD("telegram-desktop")},
    {altkey, XK_q, spawn, SHCMD("qbittorrent")},
    {altkey, XK_g, spawn, SHCMD("thunderbird")},
    {altkey, XK_m, spawn, SHCMD("env LD_PRELOAD=/usr/local/lib/spotify-adblock.so spotify %U")},
    {altkey, XK_k, spawn, SHCMD("alacritty -e ncmpcpp")},
    {altkey | ShiftMask, XK_f, spawn, SHCMD("alacritty -e ranger")},
    {altkey | ShiftMask, XK_d, spawn, SHCMD("discord")},
    {altkey | ShiftMask, XK_n, spawn, SHCMD("nitrogen")},
    {altkey | ShiftMask, XK_p, spawn, SHCMD("pavucontrol")},
    {altkey | ShiftMask, XK_v, spawn, SHCMD("viber")},
    {altkey | ShiftMask, XK_h, spawn, SHCMD("alacritty -e htop")},
    // kill all instances
    {MODKEY | ControlMask, XK_q, spawn,
     SHCMD("~/.local/bin/kill-all-instances")},

    // shortcut to view all present keybindings
    // {altkey, XK_k,   spawn, SHCMD("st vim -R
    // ~/.config/suckless/dwm/keymaps.md")},
    {altkey, XK_p, spawn, SHCMD("thorium-browser --incognito")},
    // {altkey, XK_n, spawn,
    // SHCMD("librewolf --private-window /home/ceaser/Desktop/")}, // used to
    // view pdfs

    // alacritty theme Changer
    {altkey | ControlMask, XK_t, spawn,
     SHCMD("/home/sumdahl/.local/bin/alacritty-theme-selector")},

    // rofi-menu for selecting avaiable wifi
    {altkey | ControlMask, XK_n, spawn,
     SHCMD("/home/sumdahl/.local/bin/rofi-wifi-menu.sh")},

    {altkey | ShiftMask, XK_w, spawn,
     SHCMD("feh --bg-fill --randomize --recursive $HOME/Pictures/wallpapers &")},
    //system hot keys suspned , power off and reboot and lock
    {MODKEY | ControlMask | altkey, XK_s, spawn, SHCMD("systemctl suspend")},
    {MODKEY | ControlMask | altkey, XK_l, spawn, SHCMD("betterlockscreen -l")},
    {MODKEY | ControlMask | altkey, XK_p, spawn, SHCMD("systemctl poweroff")},
    {MODKEY | ControlMask | altkey, XK_r, spawn, SHCMD("systemctl reboot")},

	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  {MODKEY,                        XK_d,      spawn,          SHCMD("rofi -show drun")},
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY | ShiftMask,           XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY | ShiftMask,           XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_s,      show,           {0} },
	{ MODKEY|ShiftMask,             XK_s,      showall,        {0} },
	{ MODKEY|ShiftMask,             XK_h,      hide,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button1,        togglewin,           {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

