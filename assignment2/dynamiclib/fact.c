#include <stdio.h>


void factorial(int numfact)
{

int fact = 1;

for (int i =1 ; i <= numfact ; i++ )
{
fact *= i;
}

printf("Result is : ");
printf("%d",fact);


}


