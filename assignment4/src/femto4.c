#include <stdio.h>
#include "utilities.h"





int main(int argc, char *argv[])
{

    if (strcmp(argv[1], "pwd") == 0)
	pwd();

    else if (strcmp(argv[1], "echo") == 0)
	echo(argc, argv);


    else if (strcmp(argv[1], "cp") == 0)
	cp(argv);


    else if (strcmp(argv[1], "mv") == 0)
	mv(argv);


    else
	printf
	    ("You haven't entered a valid command, femto shell will terminate\n");


    return 0;
}
