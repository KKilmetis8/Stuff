#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double v)
{
double a,g=10.0;
a=-g-g*0.2*v;
return a;
}

int main (void){
const double pi = 4.0 * atan(1.0);
double dt,xmax_local=0.0,xmax_global=0.0,angle=0.0,ycheck=1.0,u0=20;
int g=10,i,j,N=100;
double r[N],t[N],u[N],x[N],y[N], test_angle[N];
r[0]=0;
x[0]=0;
y[0]=0;
t[0]=0;
u[0]=20;
test_angle[0]=pi/(2*N);
dt=0.1;
for(j=0;j<N;j++)
	{
	test_angle[j+1]=test_angle[j] + pi/(2*N) ;
	for(i=0;i<N;i++)
        {
		u[i+1]=u[i]+dt*f(u[i]);
		r[i+1]=r[i]+dt*u[i];
		y[i+1]=r[i+1]*sin(test_angle[j]);
		x[i+1]=r[i+1]*cos(test_angle[j]);
			if (x[i+1]>xmax_local){
			xmax_local=x[i+1];}
		t[i+1]=t[i]+dt;
		ycheck=y[i+1];
			if (ycheck==0.0)
			{	
			break;
			}
		}
	if (xmax_local>xmax_global)
		{
		xmax_global=xmax_local;
		angle=test_angle[j];
		}
	}
printf("\n Maximum distance is %lf m .The Angle is %lf rads",xmax_global,angle);
return 0;
}
