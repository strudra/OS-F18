#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <signal.h>

#define ALWAYS_TRUE 1
#define SEC_TO_WAIT 10

void sig_func(int nmr);

int main() {
    pid_t cpid;

    cpid = fork();

    if (cpid == -1) {
        perror("fork error");
        exit(1);
    }

    if (cpid == 0) {
        while (ALWAYS_TRUE) {
            printf("I'm alive!");
            sleep(ALWAYS_TRUE);
        }
    } else {
        sleep(SEC_TO_WAIT);
        if (signal(SIGTERM, sig_func) == SIG_ERR)
            printf("\nNO SIGKILL\n");
    }

    return 0;
}
void sig_func(int nmr) {
    if (nmr == SIGTERM)
        printf("SIGTERM!\n");
}
