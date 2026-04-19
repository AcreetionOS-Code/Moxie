#include <assert.h>
#include <stdio.h>
#include "xlibre-shim.h"

int main(void)
{
    xlibre_display_t *d = xlibre_display_open("test-display");
    assert(d != NULL);

    void *conn = xlibre_get_xcb_connection(d);
    (void)conn; /* currently expected to be NULL until implemented */

    xlibre_display_close(d);

    printf("xlibre-shim basic test: OK\n");
    return 0;
}
