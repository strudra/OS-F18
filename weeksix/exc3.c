#include<stdio.h>
#include<signal.h>
#include<unistd.h>

#define ALWAYS_TRUE 1

void sigint_func(int nmr);

// SIGINT - ctrl + c
int main() {
    signal(SIGINT, sigint_func);
    while (ALWAYS_TRUE) {
        sleep(2);
    }
}

void sigint_func(int nmr) {
    if (nmr == SIGINT)
        printf("Received SIGINT Signal!");
}