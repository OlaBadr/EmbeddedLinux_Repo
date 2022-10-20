#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "shellsupport.h"

extern char newargv[30][40];

int parser(char *buf)
{

    int i = 0;			/*buffer index */
    char j = 0;			/*argument index */
    char *dollarptr = NULL;	/*pointer to the first occurance of $ */


    while (buf[i] != '\0') {
	if (buf[i] == '=') {
	    assignvar(buf);
	    return 0;		/*0 means assign variable */
	}

	i++;
    }


    /*Parser for echo $ */

    dollarptr = strchr(buf, '$');

    if (dollarptr != NULL) {
	return echoparser(buf);
    }



    /*Space parser */

    char *found = strtok(buf, " ");

    if (found == NULL) {
	strcpy(newargv[0], found);
	j++;

    }
    while (found) {
	//printf("\n parser here3");
	strcpy(newargv[j], found);
	//printf("arg %d = %s", j,argv+j );
	found = strtok(NULL, " ");
	j++;
    }

    *newargv[j] = '\0';		/*End with NULL */

    return j;			/*return number of arguments (argc) */
}



int echoparser(char *buf)
{
    char *found_s = strtok(buf, " $");
    int argv_count = 0;

    while (found_s) {
	strcpy(newargv[argv_count], found_s);
	found_s = strtok(NULL, " $");
	argv_count++;
	if (argv_count == 1) {
	    strcpy(newargv[argv_count], "$");
	    argv_count++;
	}
    }

    *newargv[argv_count] = '\0';	/*End with NULL */

    char *env_dollar = getenv(newargv[2]);
    printf("%s\n", env_dollar);

    return 0;
}
