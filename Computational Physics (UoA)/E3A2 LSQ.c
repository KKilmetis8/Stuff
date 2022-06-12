#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/*All integration has been done manually.
We utilized the known Hermite polynomials as an orthogonal base*/
int main ()
{
const double pi = 4.0 * atan(1.0);
double c0=0.0,c1,c2=0.0,c3 ;
//First Function sin(pi*x)
c1=(2/pi)*1.5;
c3=-1.6603/3.8857;
printf(" \n The Least square polynomial of sin(pi*x) is p(x)=%.1lf op0(x)+%lf op1(x)+%.1lf op2 %lf op3",c0,c1,c2,c3);
double err;
err=0.988378;
printf("\n Error: %lf",err);
//Second Function exp(-3x)
double c00,c11,c22,c33;
c00=sinh(3)/3;
c11=-2*(2+exp(6))/(9*exp(3)) * 1.5;
c22=4*(exp(6)+2)/(27*exp(3)) *(16/15);
c33=10.433/3.8857;
printf(" \n The Least square polynomial of exp(-3*x) is p(x)=%2lf op0(x) %lf op1(x)+%2lf op2 %lf op3",c00,c11,c22,c33);
double err2;
err2=0.494189;
printf("\n Error: %lf",err2);
return 0;}
	
	
	
	
	
	
	
	
	