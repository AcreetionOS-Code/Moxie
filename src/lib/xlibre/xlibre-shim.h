#ifndef XLIBRE_SHIM_H
#define XLIBRE_SHIM_H

#include <glib.h>

typedef struct _xlibre_display xlibre_display_t;

xlibre_display_t *xlibre_display_open(const char *name);
void xlibre_display_close(xlibre_display_t *display);
void *xlibre_get_xcb_connection(xlibre_display_t *display);

#endif /* XLIBRE_SHIM_H */
