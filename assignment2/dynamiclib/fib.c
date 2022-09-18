#include <stdio.h>


void Fibonacci(int numfib)
{
int Fib_arr[1000];

Fib_arr[0]= 0 ;
Fib_arr[1] = 1;

printf("The sequence is: 0");

if (numfib > 0)
{
printf(", 1");
} 

if (numfib > 1 )
{

for (int j = 1 ; j < numfib ; j++)
{
Fib_arr[j+1] = Fib_arr[j] + Fib_arr[j-1] ;
printf(", ");
printf("%d", Fib_arr[j+1] );


}

}

}
