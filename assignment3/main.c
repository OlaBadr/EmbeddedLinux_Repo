#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "myfuncs.h"

int main()
{

char repeating[] = {"Let's Goooooo> "};
char usaid[] = {"You Said: "};
char ext[]= {"exit\n"};
char exstr[] ={"Good bye :))\n"};
char rand[] = {"rand\n"};
char fact[]= {"fact\n"};
char fib[]= {"fib\n"};
char str[1000];              //static allocation
int rt = write (1 , repeating , sizeof(repeating));

while (1)
{

int str_size=0;         //input string size
int i=0;           //counter to get size of input string

fgets(str, 1000, stdin);  //read input from user

while (str[i] != '\0')   //loop to get the accurate size of str
{
str_size++;
i++;
}

if (strcmp (str , ext) == 0)
{
rt = write (1 , exstr , sizeof(exstr));
printf("\n");
break;
}

else if(strcmp (str , rand) == 0)
{
myrand();
printf("\n");
}

else if(strcmp (str , fact ) == 0)
{
int numfact;
printf("Enter a number: ");
scanf ("%d", &numfact);
factorial(numfact);
printf("\n");
}

else if(strcmp (str , fib) == 0)
{
int numfib;
printf("Enter a number: ");
scanf("%d", &numfib);
Fibonacci(numfib);
printf("\n");
}
else 
{
if (str_size > 1) //in case if fgets reads wrong input
{
rt = write (1 , usaid , sizeof(usaid));
rt = write (1 , str , (str_size-1) );
printf("\n");
}

}

if (str_size > 1) //in case if fgets reads wrong input
rt = write (1 , repeating , sizeof(repeating));

}
return 0;
}

