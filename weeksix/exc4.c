#include<stdio.h>
#include<signal.h>
#include<unistd.h>

#define ALWAYS_TRUE 1

void sig_func(int nmr);

int main() {
    if (signal(SIGKILL, sig_func) == SIG_ERR)
        printf("\nNO SIGKILL\n");
    if (signal(SIGSTOP, sig_func) == SIG_ERR)
        printf("\nNO SIGSTOP\n");
    if (signal(SIGUSR1, sig_func) == SIG_ERR)
        printf("\nNO SIGUSR1\n");

    while(ALWAYS_TRUE)
        sleep(1);
}

void sig_func(int nmr) {
    if (nmr == SIGUSR1)
        printf("SIGUSR1\n");
    else if (nmr == SIGKILL)
        printf("SIGKILL\n");
    else if (nmr == SIGSTOP)
        printf("SIGSTOP\n");
}
