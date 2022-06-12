#include <stdio.h>
#include <math.h>

double g (double x){
double g1;
g1=9+5*sqrt(x);
return g1;}

double gprime (double x){
double g2;
g2=2.5/sqrt(x);
return g2;}

int main (){
	int i;
	double xn,xn1,L,en,n; 
xn=g(0);
en=0.5*pow(10,-6);
for(i=0;i<1000;i++){
	xn1=g(xn);
xn=xn1;}

//g'max in [9,49] is g'(9) since g' is monotonically deceasing in [9,49]
L=fabs(gprime(9));
n=log( pow(2.71828182846,-log(L)) * pow(2.71828182846,log(en*(1-L)/(49-xn1))));
//n=floor(n);
n=fabs(ceil(n));
printf(" Least iterations n=%lf",n);
return 0 ;}



	
