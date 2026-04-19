#ifndef XLIBRE_SHIM_H
#define XLIBRE_SHIM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _xlibre_display xlibre_display_t;

xlibre_display_t *xlibre_display_open(const char *name);
void xlibre_display_close(xlibre_display_t *display);
void *xlibre_get_xcb_connection(xlibre_display_t *display);

#ifdef __cplusplus
}
#endif

#endif /* XLIBRE_SHIM_H */
