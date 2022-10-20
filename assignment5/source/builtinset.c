#include <strings.h>
#include <stdio.h>
#include "shellsupport.h"

extern int listindex;
extern char namelist[10][40];
extern char vallist[10][40];

void setlocal(char *var_name, int name_count, char *var_val, int val_count)
{
    int i;

    for (i = 0; i < name_count; ++i) {

	namelist[listindex][i] = var_name[i];

    }

    for (i = 0; i < val_count; ++i) {

	vallist[listindex][i] = var_val[i];

    }

    listindex++;
}



void setprint(void)
{

    int j = 0;

    while (j < listindex) {
	printf("local_vars[%d]: %s = %s\n", j, *(namelist + j),
	       *(vallist + j));
	++j;

    }

}
