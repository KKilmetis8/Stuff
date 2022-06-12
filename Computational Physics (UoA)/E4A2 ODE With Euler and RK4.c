#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
const double pi = 4.0 * atan(1.0);
//Euler
//Analytically we can calculate that the object will land in 2sqrt(3) seconds
double h,angle=pi/3,uy0;
uy0=20*sin(angle);
int g=10,i,N=100;
double y[N],t[N],uy[N],ux0=20*cos(angle);
h=2*sqrt(3)/N;
uy[0]=uy0;
y[0]=0;
t[0]=0;
FILE *fp;
fp = fopen("Euler Results.txt","w");
for(i=0;i<N;i++){
	t[i+1]=h+t[i];
	uy[i+1]=uy[i]-(h*g);
	y[i+1]=y[i]+h*(-g*t[i]+uy0);
	fprintf(fp,"\n %lf \t %lf \t %lf",t[i+1],y[i+1],uy[i+1]);
	if (y[i+1]<=0.0)
		break;
}
fclose(fp);
//4th Order Runge-Kutta
FILE *fp1;
fp1=fopen("Runge-Kutta 4 Results.txt","w");
int N2=200;
double k1[N2],k2[N2],k3[N2],k4[N2],uy4[N2],y4[N2];

uy4[0]=uy0;
y4[0]=0;
for(i=0;i<N2;i++){
	k1[i]=h*uy4[0];
	k2[i]=h*(uy4[i]-0.5*g*h);
	k3[i]=h*(uy4[i]-0.5*g*h);
	k4[i]=h*(uy4[i]-g*h);
	y4[i+1]=y4[i]+(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i])/6;
	uy4[i+1]=uy4[i]-g*h;
	fprintf(fp1,"\n %lf \t %lf \t %lf",t[i+1],y4[i+1],uy4[i+1]);
	if (y4[i+1]<=0.0)
		break;
	}
return 0;
}
