#include <stdio.h>
#include <malloc.h>
#include <sys/resource.h>
#include <string.h>

#define TEN 10
#define TWO_TEN 1024

void exercise_two();

int main() {
	exercise_two();
	return 0;
}

void exercise_two() {
	int i;
	for (i = 0; i < TEN; i++) {
		void *p = malloc(TWO_TEN * TWO_TEN * TEN);
		memset(p, 0, TWO_TEN * TWO_TEN * TEN);
		sleep(1);
		free(p);
	}
} 
