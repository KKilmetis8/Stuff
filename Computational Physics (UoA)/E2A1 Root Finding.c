#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double fu(double x)
{
	double f;
	f=pow(x,3) +4*pow(x,2) -10;
	return f;
}

double g(double x)
{
	double g;
	g=sqrt(10/(x+4));
	return g;
}
double fprime(double x)
{
	double fp;
	fp= 3*pow(x,2) + 8*x ;
	return fp;
}

int main ()
{
	int i, N=10000;
	double a=1.0, b=2.0, root=0.0, c=0.0, x=0.0; 
//Bisection
	c=(a+b)/2;
	printf("c=%lf",c);
	for(i=1;i<N;i++)
	{
		c=(a+b)/2;
		if(fu(c)==0)
		{break;}
		else if ( fu(a)*fu(c) <0)
		{b=c;}
		else 
		{a=c;}}
root=c;
printf(" Bisection Root= %lf \n", root);
//Regula Falsi
double root2=0.0;
x=0.0;
x= b-fu(b)*((b-a)/(fu(b)-fu(a)));
for(i=1;i<N;i++)
	{
		x=(a+b)/2;	
		if( fu(x) ==0)
		{break;}
		else if ( fu(a)*fu(x) <0)
		{b=x;}
		else 
		{a=x;}}
root2=x;
printf("Regula Falsi Root=%lf \n",root2);
//Fixed Point
double root3=0.0;
x=0.0;
for(i=1;i<N;i++)
{
	if(g(x)==0)
	{break;}
	else x=g(x);
	}root3=x;
printf(" Fixed Point Root= %lf \n",root3);
//Newton-Raphson
double root4=0.0, error=0.0, kr=1.365, relative_error=0.0;
x=1.0 ;//Guessimate
	for(i=0;i<N;i++)
	{
	relative_error=(kr - x)/kr;	
	if (relative_error==0.001){
	break;}               
	else x=x-fu(x)/fprime(x);
	}
root4=x;
printf(" Newton-Raphson Root= %lf \n", root4);

return 0;
}
