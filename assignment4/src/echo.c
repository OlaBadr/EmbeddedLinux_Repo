#include <stdio.h>
#include "utilities.h"

void echo(int argc, char *argv[])
{
    int i = 2;
    while (i != argc) {
	int j = 0;
	while (argv[i][j] != '\0') {
	    printf("%c", argv[i][j]);
	    j++;
	}
	printf(" ");
	i++;

    }
    printf("\n");
}
