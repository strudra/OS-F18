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
    int fd[2], stat;
    pipe(fd);
    pid_t cpid, ccpid, retrieve_id;
    pid_t tmp;

    cpid = fork();
    if (cpid == 0) {
    	printf("1st child. ID => %d\n", getpid());
    	sleep(SEC_TO_WAIT);
    	read(fd[0], retrieve_id, sizeof(retrieve_id));
    	kill(retrieve_id, SIGSTOP);
    }

    if (ccpid == 0) {
    	sleep(SEC_TO_WAIT);
    	printf("2nd child. ID => %d\n", getpid());
    } else {
    	write(fd[1], tmp, sizeof(tmp)+1);
    	waitpid(ccpid, &stat, 0);
    }
    close(fd[0]);
    close(fd[1]);
}

void sig_func(int nmr) {
    if (nmr == SIGTERM)
        printf("SIGTERM!\n");
}
