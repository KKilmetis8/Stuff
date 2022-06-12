#include <stdio.h>
#include <math.h>

int main (void)
{

//Define Variable
double a, b, c, d, x1, x2 ;

a=0;

//Main Body

printf("Hello World!");
printf("\n I'll check if a Quadratic Equation has real solution");
printf("\n If it has a real solution,i'll present it to you");
printf("\n The Quadratic Equation has the general form ax^2 + bx +c");
while (a==0)
{
printf("\n Please give value of a, a can not be zero");
scanf(" %lf", &a);
}


printf("\n Please give value of b");
scanf(" %lf", &b);

printf("\n Please give value of c");
scanf("%lf", &c);

d = (b*b) - (4 * a * c) ;

if ( d < 0.0 )
{
	printf("\n There are no real solutions");
}
else if (d == 0.0) 
{
x1 = -b/ (2*a);
printf("\n There is only one real solution x= %lf", x1);
}
else
{
x1 = (-b - sqrt(d)) / (2 * a);
x2 = (-b + sqrt(d)) / (2 * a);
printf("\n There are 2 real solutions");
printf("\n x1 = %lf", x1);
printf("\n x2 = %lf", x2);
}

return 0;
}
