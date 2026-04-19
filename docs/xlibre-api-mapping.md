xlibre API mapping — initial draft

Overview

This document tracks API mappings and migration notes for porting Moxie
from traditional Xlib/XCB/X11 usage to xlibre-based APIs. It was generated
after an initial code audit (2026-04-19) that found extensive Xlib and XCB
usage in src/x11/, backends/x11/, cogl/, and clutter/x11/.

Audit summary

- Common symbols found: XOpenDisplay, XCreateWindow, XGetXCBConnection, XGetErrorText
- Widespread use of Xlib includes (<X11/Xlib.h>, <X11/Xatom.h>, etc.)
- Heavy xcb usage via XGetXCBConnection and xcb_* calls (randr, res, render, etc.)

Priority files/directories (from the audit)

- src/backends/x11/meta-backend-x11.c
- src/backends/x11/meta-output-xrandr.c
- src/x11/* (window-x11.c, meta-x11-display.c, xprops.c, group.c)
- cogl/winsys (cogl-winsys-glx.c, cogl-winsys-egl-x11.c, cogl-xlib-renderer.c)
- clutter/clutter/x11/*

Mapping table (fill in mappings)

| X11/XCB API | xlibre equivalent | Notes / action item |
|-------------|-------------------|---------------------|
| XOpenDisplay | xlibre_display_open() | Central display open; wrap platform details |
| XCreateWindow| xlibre_window_create() | Map window properties and visual information |
| XGetXCBConnection | xlibre_get_xcb_connection() | Provide an XCB-compatible connection or native xlibre interface |
| xcb_randr_* | xlibre_randr_* | Map RandR queries to xlibre output enumeration and modes |

Next steps

1. Populate mapping table with concrete xlibre API names.
2. Implement a small shim/core module that provides display/connection
   abstraction for xlibre to replace XOpenDisplay/XGetXCBConnection.
3. Start porting backend (meta-backend-x11) using the shim.

Notes

Avoid changing Cogl/Clutter behavior until a stable shim exists. Keep
Wayland disabled per project policy.
