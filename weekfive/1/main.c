#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 50
#define SLEEP_STEP 10

int threads[NUM_THREADS];

void *sayHi(int i);

void sequential()
{
    int rc, i;
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, sayHi, (void*)i);
        if (rc) {
            printf("\n ERROR - Exiting with code -> %d \n", rc);
            exit(1);
        }
        rc = pthread_join(threads[i], NULL);
        printf("\n Completed Thread -> %d. NEW THREAD -> (%d) AT STEP -> %d.\n", (int) pthread_self(), threads[i], i);
    }
}

void parallel()
{
    int rc, i;
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, sayHi, (void*)i);
        if (rc) {
            printf("\n ERROR - Exiting with code -> %d \n", rc);
            exit(1);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        printf("\n Completed Thread -> %d. NEW THREAD -> (%d) AT STEP -> %d.\n", (int) pthread_self(), threads[i], i);
    }
}

int main(int argc, char *argv[]) {
    sequential();
    // parallel();
}

void *sayHi(int i) {
    printf("Hello from thread %d - created in iteration %d \n", (int) pthread_self(), i);
    pthread_exit(NULL);
}