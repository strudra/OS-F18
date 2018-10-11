#include <stdio.h>
#include <malloc.h>
#include <sys/resource.h>
#include <string.h>

#define TEN 10
#define TWO_TEN 1024

void exercise_four();

int main() {
	exercise_four();
	return 0;
}

void exercise_four() {
	struct rusage m_usage;
	int i;
	for (i = 0; i < TEN; i++) {
		void *p = malloc(TWO_TEN * TWO_TEN * TEN);
		memset(p, 0, TWO_TEN * TWO_TEN * TEN);
		getrusage(RUSAGE_SELF, &m_usage);
		printf("usage = %ld\n", m_usage.ru_maxrss);
		sleep(1);
	}
} 
