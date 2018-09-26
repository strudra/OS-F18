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
    pid_t cpid;

    pipe(fd);

    cpid = fork();

    if (cpid == -1) {
        perror("fork error");
        exit(1);
    }

    if (cpid == 0) {
        // child -> close input pipe
        close(fd[0]);
        write(fd[1], c1, strlen(c1)+1);
        exit(0);
    } else {
        // parent -> close output pipe
        close(fd[1]);
        read(fd[0], c2, sizeof(c2));
        printf("Piped string is: %s", c2);
    }

    return 0;
}