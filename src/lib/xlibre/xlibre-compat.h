#ifndef XLIBRE_COMPAT_H
#define XLIBRE_COMPAT_H

/* Minimal compatibility header to map traditional Xlib types/functions
 * to the xlibre shim for Moxie. This is a temporary compatibility layer
 * used during the xlibre port to avoid editing every include at once.
 */

#include "xlibre-shim.h"

/* Basic X types mapped to xlibre equivalents or simple aliases */
typedef xlibre_display_t Display;
typedef unsigned long Window;
typedef unsigned long Atom;

/* Provide XCB visibility if available */
#ifdef HAVE_XCB
#include <xcb/xcb.h>
#else
/* forward-declare minimal xcb types */
struct xcb_connection_t;
typedef struct xcb_connection_t xcb_connection_t;
#endif

/* Map common functions to xlibre shim functions */
#define XOpenDisplay(name) ((Display*) xlibre_display_open(name))
#define XCloseDisplay(d) xlibre_display_close((xlibre_display_t*)(d))
#define XGetXCBConnection(d) ((xcb_connection_t*) xlibre_get_xcb_connection((xlibre_display_t*)(d)))

/* Memory helpers: some code calls XFree on returned pointers */
#include <stdlib.h>
#define XFree(ptr) free(ptr)

/* Basic constants */
#ifndef None
#define None 0
#endif

#endif /* XLIBRE_COMPAT_H */
