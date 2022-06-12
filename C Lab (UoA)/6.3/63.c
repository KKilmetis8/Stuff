#include <stdio.h>

int main(void)
{

double gin,ep,i,teltim ;


gin = 1.0;
i=1.0;
teltim = 0.0;

printf("Hello World!\n");
printf("Tha ypologiso to apeiro ginomeno 1 - 1/4k^2 \n ");
printf("Dose mou ena epsilon tetoio oste otan |1- ak|< e na stamathsei h epanalypsh\n");
scanf("%lf",&ep);

while ( (1.0-teltim) > ep)
{
	teltim = 1.0 - ( 1.0/(4.0*i*i) );
	gin = gin * teltim ;
	i=i+1.0;
}

i= i - 1.0;
printf(" To ginomeno einai %lf \n " , gin);
printf(" Oi synolikoi oroi einai %lf \n" , i);
printf(" O teleftaios oros htan %lf \n" , teltim);

return 0;
}