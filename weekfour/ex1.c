#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
    int n = 73;
    pid_t pid;

    switch(pid=fork()) {
        case -1:
            // went wrong
            perror("fork");
            exit(1);

        case 0:
            // child
            printf("Hello from child [%d - %d]\n", pid, n);
            exit(0);

        default:
            // parent
            printf("Hello from parent [%d - %d]\n", pid, n);
    }

    return 0;
}