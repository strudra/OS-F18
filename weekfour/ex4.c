#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 200

int main () {
    char command[MAXLENGTH];

    gets(command);
    system(command);

    return(0);
}