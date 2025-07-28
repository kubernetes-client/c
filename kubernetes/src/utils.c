#include <stdlib.h>
#include "../include/utils.h"
#include <string.h>
#include "config.h"

// based on https://github.com/libssh/libssh-mirror/commit/247983e9820fd264cb5a59c14cc12846c028bd08#diff-744295d01685fa411dbfd78679ea20b51dfa4ac7d2d722df53f3d86d728493f8
#if !defined(HAVE_STRNDUP)
char *strndup(const char *s, size_t n)
{
    char *x = NULL;

    if (n + 1 < n) {
        return NULL;
    }

    x = malloc(n + 1);
    if (x == NULL) {
        return NULL;
    }

    memcpy(x, s, n);
    x[n] = '\0';

    return x;
}
#endif /* ! HAVE_STRNDUP */

#if !defined(HAVE_STRTOK_R)
char *strtok_r(char *str, const char *delim, char **saveptr)
{
    return strtok(str, delim);
}
#endif /* ! HAVE_STRTOK_R */
