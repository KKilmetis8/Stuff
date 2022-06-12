#include <stdio.h>
#include <math.h>


int main (void)
{
 
//Variables
double x, h, e;
char end;

//Main Body
printf("\n Hello Wolrd!");
printf("\n I'll calculate the height and the Area of an Equilateral triangle");
printf("\n Give me the length of the sides");
scanf("%lf",&x);

h = sqrt(3) * x / 2 ;
e = h * x / 2 ;

printf("\n The height is %lf", h);
printf("\n The Area of the Triangle is %lf", e);
 
return 0;
}