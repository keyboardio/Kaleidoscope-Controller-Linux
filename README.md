<!-- -*- mode: markdown; fill-column: 8192 -*- -->
Application-based Layer Switcher for Kaleidoscope
=================================================

A simple tool written in [Python][py] to track the active application under Linux, and switch layers based on this information. In other words, this application will switch the layer on the keyboard, based on which application is currently active.

On the firmware side, this requires the [Focus][k:focus] plugin to be installed and active, and a Focus command enabling layer changes. Such a hook is found herein, in the `hooks/kaleidoscope-layer-switch.h` file. You can copy that to your sketch verbatim, and use it like any other Focus hook.

On the host side, we need [pygtk][py:gtk], [python-wnck][py:wnck], and [python-serial][py:serial].

To change which layer each recognised application should switch to, simply edit the `src/kaleidoscope-app-tracker.conf.json` file. It's a map (or dictionary, if so you prefer) of application names and layer pairs. Each key is the name of an application, and the value is the number of the layer the keyboard should switch to, if that application is active. Once an application becomes inactive, the layer gets switched off, and we return to the previous state.

 [py]: https://www.python.org/
 [k:focus]: https://github.com/keyboardio/Kaleidoscope-Focus
 [py:gtk]: http://www.pygtk.org/
 [py:wnck]: https://developer.gnome.org/libwnck/stable/
 [py:serial]: https://github.com/pyserial/pyserial

# License

The code is released under the terms of the GNU GPL, version 3 or later. See the
COPYING file for details.
