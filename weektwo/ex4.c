#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}