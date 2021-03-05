#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <magic.h>


//#define DEFAULT_FLAGS MAGIC_COMPRESS|MAGIC_CONTINUE

const char *check(char *filename, int flags) {
    magic_t cookie = magic_open(flags);
    if (cookie == NULL) {
        return NULL;
    }
    magic_load(cookie, NULL);
    const char *str = magic_file(cookie, filename);
    size_t len = strlen(str) + 1;
    char *desc = (char *) malloc(len);
    memcpy(desc, str, len);
    magic_close(cookie);
    return desc;
}


const char *checkBuf(void *buf, size_t size, int flags) {
    magic_t cookie = magic_open(flags);
    if (cookie == NULL) {
        return NULL;
    }
    magic_load(cookie, NULL);
    const char *str = magic_buffer(cookie, (void *)buf, size);
    size_t len = strlen(str) + 1;
    char *desc = (char *) malloc(len);
    memcpy(desc, str, len);
    magic_close(cookie);
    return desc;
}
