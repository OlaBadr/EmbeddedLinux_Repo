#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{

char repeating[] = {"Let's Goooooo> "};
char usaid[] = {"You Said: "};
char ext[]= {"exit\n"};
char exstr[] ={"Good bye :))\n"};
char str[1000];              //static allocation

while (1)
{
int str_size=0;         //input string size
int i=0;           //counter to get size of input string

int rt = write (1 , repeating , sizeof(repeating));
fgets(str, 1000, stdin);

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

else 
{
rt = write (1 , usaid , sizeof(usaid));
rt = write (1 , str , str_size );
printf("\n");

}
}
return 0;
}

