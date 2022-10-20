
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "shellsupport.h"

/*Global Variables*/
int listindex = 0;
char namelist[10][40];
char vallist[10][40];
char newargv[30][40];

int main()
{

    int mypid = getpid();
    printf("parent pid= %d\n", mypid);

    while (1) {

	char buf[100];
	printf("You're in a Nutshell, Your Wish is My Command $ ");
	fgets(buf, 100, stdin);
	buf[strlen(buf) - 1] = '\0';


	if (strlen(buf) == 0)	/*support enter */
	    continue;

	int newargc = parser(buf);	/*start parser */



	char *ptrarr[30];

	for (int i = 0; i < newargc; i++) {
	    ptrarr[i] = &newargv[i];

	}

	ptrarr[newargc] = NULL;

	/*builtin processes */
	if (strcmp(newargv[0], "set") == 0)	//set: builtin command
	{
	    setprint();
	    continue;
	}

	else if (strcmp(newargv[0], "export") == 0)	//export: builtin command
	{
	    int ret = exportenv();
	    //check on the return of exportenv
	    if (ret == 0)
		printf("export success\n");

	    else if (ret < 0)
		printf("export failed\n");

	    continue;
	}


	//printf("newargc = %d\n",newargc);

	/*for (int i=0 ; i < newargc ; i++)
	   {
	   printf("argv[%d] = %s\n",i ,newargv[i]);

	   } */




/* if parent: return = childID .. but if duplicated child: return =0*/
/*child will start from here*/
	int childpid = fork();


	if (childpid < 0)
	    printf("Fork Failed\n");

	else if (childpid > 0) {	/*I'm the parent and will wait on the child */
	    int status;
	    wait(&status);
	    //printf(" I'm the parent my ID =%d, statues = %d\n",mypid,WIFEXITED(status));                  
	}

	else if (childpid == 0) {	/*I'm the child */
	    //printf("I'm the child\n");
	    if (newargc > 0) {	/*parser will return the count of arguments */
		if (execvp(ptrarr[0], ptrarr) < 0) {	/*open new system builtin process */
		    printf("execvp failed\n");
		    exit(1);
		}
	    }

	    else if (newargc == 0)
		continue;

	    else
		printf("parser failed\n");
	}

    }

}
