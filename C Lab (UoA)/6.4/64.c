#include <stdio.h>

int main(void)
{

double sum,ep,epr,pros,i,gin,teltim;
int chr;

printf(" Hello World \n");
printf(" Press 1 for Sum \t Press anything else for Product \n");
scanf("%d",&chr);
switch ( chr ){
case 1 : 
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

default :

gin = 1.0;
i=1.0;
teltim = 0.0;

printf("Hello World!\n");
printf("Tha ypologiso to apeiro ginomeno 1 - 1/4k^2 \n ");
printf("Dose mou ena epsilon tetoio oste otan |1- ak|< e na stamathsei h epanalypsh\n");
scanf("%lf",&epr);

while ( (1.0-teltim) > epr)
{
	teltim = 1.0 - ( 1.0/(4.0*i*i) );
	gin = gin * teltim ;
	i=i+1.0;
}

i= i - 1.0;
printf(" To ginomeno einai %lf \n " , gin);
printf(" Oi synolikoi oroi einai %lf \n" , i);
printf(" O teleftaios oros htan %lf \n" , teltim);
}
return 0;
}
