#include <stdlib.h>
#include <strings.h>
#include "shellsupport.h"

extern int listindex;
extern char namelist[10][40];
extern char vallist[10][40];
extern char newargv[30][40];

int exportenv(void)
{
    int i = 0;

    while (i < listindex) {
	if (strcmp(namelist[i], newargv[1]) == 0) {
	    return setenv(namelist[i], vallist[i], 1);	/*in success return 0 */
	}

	++i;

    }

    return -1;			/*in failure return -1 */

}
