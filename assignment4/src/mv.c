#include "utilities.h"
#include <stdio.h>

void mv(char *argv[])
{
    cp(argv);
    remove(argv[2]);

}
