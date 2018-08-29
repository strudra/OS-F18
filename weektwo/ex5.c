#include <stdio.h>
#include <stdlib.h>

void print_figure_one(int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}
}

void print_figure_two(int x) {
	int i = 0;
	for (; i < x/2; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}
	for (++i; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}
}

void print_figure_three(int x) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			printf("%c", '*');
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[]) {
	int n, m;
	scanf("%d", &n);
	printf("Enter a choice (0, 1 or 2)\n");
	scanf("%d", &m);

	if (m == 0) {
		print_figure_one(n);
	} else if (m == 1) {
		print_figure_two(n);
	} else if (m == 2) {
		print_figure_three(n);
	}

	return 0;
}

