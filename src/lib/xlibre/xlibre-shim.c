/* xlibre shim with optional XCB bridge for Moxie
 * If libxcb is available at build time, HAVE_XCB will be defined and
 * xlibre_get_xcb_connection will return a live xcb_connection_t*.
 */

#include "xlibre-shim.h"
#include <stdlib.h>
#include <string.h>

#ifdef HAVE_XCB
#include <xcb/xcb.h>
#endif

struct _xlibre_display {
    char *name;
    void *backend; /* opaque backend pointer for future use */
};

xlibre_display_t *
xlibre_display_open(const char *name)
{
    xlibre_display_t *d = malloc(sizeof(*d));
    if (!d)
        return NULL;

    d->name = (name != NULL) ? strdup(name) : strdup("default");
    d->backend = NULL; /* TODO: initialize real backend */
    return d;
}

void
xlibre_display_close(xlibre_display_t *display)
{
    if (!display)
        return;

    free(display->name);
    free(display);
}

void *
xlibre_get_xcb_connection(xlibre_display_t *display)
{
    (void)display;
#ifdef HAVE_XCB
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    if (!conn)
        return NULL;
    if (xcb_connection_has_error(conn)) {
        xcb_disconnect(conn);
        return NULL;
    }
    return conn;
#else
    return NULL;
#endif
}
