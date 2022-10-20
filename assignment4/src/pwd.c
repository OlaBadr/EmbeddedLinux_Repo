#include <unistd.h>
#include <stdio.h>
#include "utilities.h"

void pwd(void)
{

    char buf[100];
    getcwd(buf, sizeof(buf));

    int i = 0;
    while (buf[i] != '\0') {
	printf("%c", buf[i]);
	i++;
    }
    printf("\n");
}
