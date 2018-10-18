#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_FRAMES 10
#define NUMBER_OF_BITS_FOR_AGING 31
#define EMPTY_VAL -1
#define TO_READ 1

typedef int bool;
#define true 1
#define false 0

int p[NUMBER_OF_FRAMES];
int a[NUMBER_OF_FRAMES];

int main()
{
	FILE* fp = fopen("9.txt", "r");
	int i;
	for (i = 0; i < NUMBER_OF_FRAMES; i++)
		p[i] = EMPTY_VAL;
	i = 0;
	int t = 0, n_of_miss = 0, j;
	
	while (fscanf(fp, "%d", &j) == TO_READ) {
		bool fault = true;
		int elder = 0;
		
		for (i = 0; i < NUMBER_OF_FRAMES; i++) {
			if (p[i] == j) {
				a[i] = (1 << (NUMBER_OF_BITS_FOR_AGING - 1)) & (a[i] >> 1);
				fault = false;
			} else {
				a[i] = a[i] >> 1;
			}
			if (a[i] < a[elder] || p[i] == EMPTY_VAL) 
				elder = i;
		}

		++t;
		if (!fault) continue;
		++n_of_miss;
		a[elder] = 1 << (NUMBER_OF_BITS_FOR_AGING - 1);
		p[elder] = j;				
	}	 

	
	printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", NUMBER_OF_FRAMES, t, t - n_of_miss, n_of_miss);
	printf("hits/miss => %.2f\n", (double)(t-n_of_miss)/(n_of_miss));
	
	return 0;
}
