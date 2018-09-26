#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() {
    char c1[] = "The string to be copied.";
    char c2[MAX_SIZE];

    int fd[2];

    pipe(fd);

    write(fd[1], c1, strlen(c1)+1);

    read(fd[0], c2, sizeof(c2));
    printf("Piped string is: %s", c2);

    close(fd[0]);
    close(fd[1]);

    return 0;
}