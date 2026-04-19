#include <assert.h>
#include <stdio.h>
#include "xlibre-shim.h"
#ifdef HAVE_XCB
#include <xcb/xcb.h>
#endif

int main(void)
{
    xlibre_display_t *d = xlibre_display_open("test-display");
    assert(d != NULL);

#ifdef HAVE_XCB
    void *conn = xlibre_get_xcb_connection(d);
    if (conn) {
        /* success: disconnect immediately */
        xcb_disconnect((xcb_connection_t*)conn);
    }
#endif

    xlibre_display_close(d);

    printf("xlibre-shim basic test: OK\n");
    return 0;
}
