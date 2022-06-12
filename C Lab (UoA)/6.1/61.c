#include <stdio.h>


int main ()
{
double sum, ep, pros,i;

printf("\n Tha ypologiso to athrisma Apeiron orwn 1/k . Apo k=1 ");

sum = 0.0;
ep = 0.0005;
pros= 1.0;
i= 1.0;

while  ( pros >= ep )
{
pros = 1/i ;
sum = sum + pros ;
i = 1 + i ; 
}

printf("\n To plithos ton oron einai = %lf", i-1);
printf("\n To athroisma einai = %lf", sum);

return 0;
}