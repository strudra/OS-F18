#include <stdio.h>
#include <stdlib.h>

void print_figure(int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 2 * x - 1; j++) {
			if ((j < x - i - 1) || (j > (x + i - 1))) {
				printf("%c", ' ');
			} else {
				printf("%c", '*');
			}
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	print_figure(n);
	return 0;
}

