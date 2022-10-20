#include <stdlib.h>
#include <strings.h>
#include "shellsupport.h"


void assignvar(char *buf)
{

    int i = 0;			/*buffer index */
    int varval_count = 0;
    int varname_count = 0;
    char varname[30];
    char varval[10];

/*Get the string before = sign to be the variable name*/
    while (buf[i] != '=') {
	if (buf[i] == ' ' && (i == 0 || buf[i - 1] == ' ')) {
	    continue;
	} else {
	    varname[varname_count] = buf[i];
	    ++i;
	    ++varname_count;
	}
    }

    varname[varname_count] = '\0';
    ++i;

/*Get the string after = sign to be the variable value*/
    while (buf[i] != '\0') {
	varval[varval_count] = buf[i];
	++i;
	++varval_count;
    }

    varval[varval_count] = '\0';

    setlocal(varname, varname_count, varval, varval_count);	/*store variable and its value */


}
