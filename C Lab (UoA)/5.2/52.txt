#include <stdio.h>
#include <math.h>

int main (void)
{
double a,b,sum,h,n ;
int i ;

printf("\n Hello World");
printf("\n Dose katw fragma oloklhromatos \n");
scanf("%lf",&a);
printf("\n Dose anw fragma oloklhromatos \n");
scanf("%lf",&b);
printf("\n Dose arithmo stoixiodwn parallilogramwn \n");
scanf("%lf", &n);

h= (b - a) / n ;

sum=0.0;

for (i=0; i<=n; ++i)
{
sum = sum + ( cos( (i*h)+a )*h );
}
sum = sum - (h * cos(b));

printf("\n To oloklhromata isoutai me %lf", sum);
return 0;
}