#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f (double x)
{
	double fx;
	fx=x*x*exp(x)*cos(x);
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
double x[5]={-1.0,-0.9,-0.8,-0.7,-0.6},xseek=-0.78;
double fxseek=0.0,theta;
int i,j;
//We'll do Newton's method first. Since maxrank=5-1=4 we need 4 differences
double d[4][4];

//Filling in initial differences
for (i=0;i<4;i++){
	if (i==0){
		d[0][0]=f(x[1])-f(x[0]);
		printf("d[0][0]=%lf \n",d[0][0]);}
	else{
		d[0][i]=f(x[i+1])-f(x[0]);
		printf("d[0][%d]=%lf \n", i,d[0][i]);}
}
//Filling in higher ranks
for(i=1;i<4;i++){
	for(j=1;j<4;j++){
		d[i][j]=d[i-1][j]-d[i-1][i-1];
		printf("d[%d][%d]=%lf \n", i,j,d[i][j]);
}}

//Constant difference of 0.1 theta=(x+1)/0.1=1=10*(x+1)
fxseek=f(x[0]);
theta=10*(xseek+1);
for (i=1;i<4;i++){
	fxseek=fxseek+d[i][i]*comb(theta,i);}
printf("Using Newton's Interpolation polynomial f(%lf)=%lf \n",xseek,fxseek);

//Lagrange's Interpolation
double L[5],Pro,fxseek2=0.0;
int r,t;
for(r=0;r<5;r++){
Pro=1.0;
	for(t=0;t<5;t++){
		if (t==r)
			t++;
		Pro=Pro*(xseek-x[t])/(x[r]-x[t]);
	}
L[r]=Pro;
}
for(r=0;r<5;r++){
	fxseek2=fxseek2+L[r]*f(x[r]);}
printf("Using Lagrange's Interpolation polynomial f(%lf)=%lf \n",xseek,fxseek2);
printf("True Value f(%lf)=%lf \n",xseek,f(xseek));
return 0;
}

//Very small theta means Newton's whole stich fucking sucks.
//Exactly like the second half of his life.  Smart guy tho.
//Don't leave that it in.
