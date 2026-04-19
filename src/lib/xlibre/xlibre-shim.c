/* xlibre shim basic implementation for Moxie
 * Provides simple open/close and an XCB bridge stub.
 */

#include "xlibre-shim.h"
#include <stdlib.h>
#include <string.h>

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
    (void)display; /* stub for now */
    return NULL;
}
