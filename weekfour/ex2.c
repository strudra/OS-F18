#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBEROFTIMESONE 3
#define NUMBEROFTIMESTWO 5

int main() {
    for (int i = 0; i < NUMBEROFTIMESONE; i++) {
        fork();
    }
    sleep(5);

    return 0;
}