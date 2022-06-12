#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double f (double x)
{
	double fx;
	fx=sin(x);
	return fx;
}

double comb (int x,int y)
{
	double c,xf=1.0,yf=1.0,diff=1.0;
	int i;
	for(i=1;i<=x;i++){
		xf=xf*i;}
	for(i=1;i<=y;i++){
		yf=yf*i;}
	for(i=1;i<=abs(x-y);i++){
		diff=diff*i;}
	c=xf/(yf*diff);
return c;
}

int main ()
{
//We'll need a data set in order to interpolate.We'll create one randomly,
//based on user input.
char *n[6]={"Zero","First","Second","Third","Fourth","Fifth"};
int i,j,order;
const double pi = 4.0 * atan(1.0);
printf(" What order of interpolation polynomial would you like to compute \n");
printf(" This program supports up to fifth-order interpolation polynomials \n");
//Ensures proper user input
do
{
	scanf("%d",&order);
	if (order>5 || order<1)
		printf("Not acceptable input");
}
while( order>5 || order<1);
order=order+1;
//Creates a data set
double x[order], y[order], rng=0.0;
srand(time(NULL));
rng=rand()/RAND_MAX %5;
for(i=0;i<order;i++)
{
	x[i]=rng;
	y[i]=f(rng);
	rng=rng+5.0; //Ensures constant differences.
}
//Filling in initial forward differences
double d[order][order];
	for (i=0;i<order;i++){
	if (i==0){
		d[0][0]=f(x[1])-f(x[0]);
		}
	else{
		d[0][i]=f(x[i+1])-f(x[0]);
		}}
//Filling in higher ranks
for(i=1;i<order;i++){
	for(j=1;j<order;j++){
		d[i][j]=d[i-1][j]-d[i-1][i-1];
}}
//Constant difference of 5 theta=(x+1)/5
double theta=10*(x[0]+1);
double c[order];
for(i=0;i<order;i++){
	c[i]=comb(theta,i);
}
//Prints the polynomial
printf(" The zero order is %lf",y[0]);
for (i=1;i<order;i++)
	{
	printf("\n  The %s order is %lf*%lf",n[i],c[i],d[i][i]);
	}
//Calculating the Derivative on two given points.
double fp[2][3],xs=pi/3,h[3]={pi/12,0.1,0.001};
for(i=0;i<2;i++)
{for(j=0;j<3;j++){
	fp[i][j]=(f(xs+h[j])-f(xs))/h[j];
}
xs=pi/6;
}
printf("\n f'(pi/3)= %lf with a step of %lf \n",fp[0][0],h[0]);
printf(" f'(pi/3)= %lf with a step of %lf \n",fp[0][1],h[1]);
printf(" f'(pi/3)= %lf with a step of %lf \n",fp[0][2],h[2]);
printf(" True value of f'(pi/3) is %lf \n",cos(pi/3));
printf(" f'(pi/6)= %lf with a step of %lf \n",fp[1][0],h[0]);
printf(" f'(pi/6)= %lf with a step of %lf \n",fp[1][1],h[1]);
printf(" f'(pi/6)= %lf with a step of %lf \n",fp[1][2],h[2]);
printf(" True value of f'(pi/6) is  %lf \n",cos(pi/6));
return 0;
}