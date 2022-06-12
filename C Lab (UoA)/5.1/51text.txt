#include <stdio.h>
#include <math.h>

int main (void)
{
double b,a,sum,h,n,exres,diff;
int i;
printf("\n Tha oloklirosw to cos(x) meso  toy kanona toy trapeziou kai tha to sygrinw me to akrives apotelesma  \n");
printf("\n Dose to kato fragma toy olokliromatos \n");
scanf("%lf",&a);
printf("\n Dose to pano fragma toy olokliromatos \n");
scanf("%lf",&b);
printf("\n Dose ton arithmo stoixiodwn trapeziwn \n");
scanf("%lf",&n);
h= (b - a) / n;
sum = 0.0;

exres = sin(b) - sin(a) ;

for (i=0; i<n; ++i)
 {
 sum = sum + ((cos(a+(h*i)))*h) ;
 }
 
 sum = sum - ((h * (cos(b) + cos(a)))/2);
 
 printf("\n arithmitiko apotelesma = %lf ",sum);
 printf("\n akrives apotelesma = %lf ",exres);
 
 diff = fabs(sum - exres);
 printf("\n diafora = %lf", diff);
 
 return 0;
}