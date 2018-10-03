#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *new_realloc(void *p, size_t begin_length, size_t end_length);

int main() {
    char *str;
    str = (char *)malloc(20);
    strcpy(str, "hey there instructor");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *)new_realloc(str, 20, 21);
    strcat(str, "!");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);

    return 0;
}

void *new_realloc(void *p, size_t begin_length, size_t end_length) {
    if (end_length == 0) { free(p); return NULL; }
    else if (begin_length >= end_length) return p;
    else if (!p) return malloc(end_length);
    else {
        void *pp = malloc(end_length);
        memcpy(pp, p, begin_length);
        free(p);
        return pp;
    }
}