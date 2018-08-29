#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char const *argv[]) {
	char* input_string = input_string = (char*) malloc(255 * sizeof(char));
	scanf("%s", input_string);
	for (int i = strlen(input_string) - 1; i >= 0; i--) {
		printf("%c", input_string[i]);
	}
	return 0;
}