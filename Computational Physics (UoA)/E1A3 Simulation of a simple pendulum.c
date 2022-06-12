#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//We're making a Gaussian distribution around the theoretical value of the Period using the Box-Muller Transformation
double Gaussian(double m, double s)	
{				        /* mean m, standard deviation s */
const double PI_2=2*3.14159265359; 
static double z1,z2,u1,u2;
static int have=0;
	if (have){
		have=0;
		return z1 ;}
	else{

u1=(double)rand()/(double)RAND_MAX;
u2=(double)rand()/(double)RAND_MAX;
z1=sqrt(-2*log(u1))*cos(PI_2*u2);
z2=sqrt(-2*log(u1))*sin(PI_2*u2);

z1=z1*s+m;
z2=z2*s+m;
return z2;
}}

int main (){	
double g,dg,T_theory,T, sum1=0.0, sum2=0.0, sum3=0.0, sum4=0.0, g1=0.0, g2=0.0, g3=0.0, g4=0.0, dg1, dg2, dg3, dg4; 
const double g_theory=9.8196,dl=0.01,dt=0.1,PI_2=2*3.14159265359; ;
int i,Ntoy=10000;

//If l=0.2m
T_theory=PI_2*sqrt(0.2/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum1=sum1+T;
}
sum1=sum1/Ntoy;
g1=PI_2*PI_2*0.2/pow(sum1,2);
printf("g1=%lf \t",g1);
dg1=sqrt(pow(dl/0.2,2)+pow(2*dt/sum1,2));

//If l=0.4m
T_theory=PI_2*sqrt(0.4/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum2=sum2+T;
}
sum2=sum2/Ntoy;
g2=PI_2*PI_2*0.4/pow(sum2,2);
printf("g2=%lf \t",g2);
dg2=sqrt(pow(dl/0.4,2)+pow(2*dt/sum2,2));

//If l=0.6m
T_theory=PI_2*sqrt(0.6/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum3=sum3+T;
}
sum3=sum3/Ntoy;
g3=PI_2*PI_2*0.6/pow(sum3,2);
printf("g3=%lf \t",g3);
dg3=sqrt(pow(dl/0.6,2)+pow(2*dt/sum3,2));

//If l=0.8m
T_theory=PI_2*sqrt(0.8/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum4=sum4+T;
}
sum4=sum4/Ntoy;
g4=PI_2*PI_2*0.8/pow(sum4,2);
printf("g4=%lf \n",g4);
dg4=sqrt(pow(dl/0.8,2)+pow(2*dt/sum4,2));

printf("T1=%lf \t T2=%lf \t T3=%lf \t T4=%lf \n",sum1,sum2,sum3,sum4);
g=(g1+g2+g3+g4)/4;
dg=sqrt(dg1*dg1+ dg2*dg2+ dg3*dg3+ dg4*dg4);
printf("Using the mean values g=%lf +- %lf \n",g,dg);

//least square fit y=A+Bx
double sumx=0.0, sumx2=0.0, sumy=0.0, sumxy=0.0, sumsy=0.0;
double A,dA,B,dB,D,sy;
double l1=sqrt(0.2), l2=sqrt(0.4), l3=sqrt(0.6), l4=sqrt(0.8);


sumx=l1+l2+l3+l4;
sumx2=pow(l1,2)+pow(l2,2)+pow(l3,2)+pow(l4,2);
sumy=sum1+sum2+sum3+sum4;
sumxy=l1*sum1+l2*sum2+l3*sum3+l4*sum4;

D=Ntoy*sumx2-sumx*sumx;
A=(sumx2*sumy-sumx*sumxy)/D;
B=(Ntoy*sumxy-sumx*sumy)/D;

sumsy=pow(sum1-A-B*l1,2)+pow(sum2-A-B*l2,2)+pow(sum3-A-B*l3,2)+pow(sum4-A-B*l4,2);
sy=sqrt(sumsy/(Ntoy-2));
dA=sy*sqrt(sumx2/D);
dB=sy*sqrt(Ntoy/D);

double gfit=pow(PI_2/B,2);
double dgfit=dB/B;

printf("Using the Least Square linear fit g=%lf +- %lf \n",gfit,dgfit);
printf("A=%lf +- %lf \t B=%lf +- %lf \n",A,dA,B,dB);

//if we had a systematic error of +5cm
printf(" Should we introduce a systematic error of +5cm the results would be as follows \n"); 
Ntoy=Ntoy/2;
//If l=0.25m
T_theory=PI_2*sqrt(0.25/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum1=sum1+T;
}
sum1=sum1/Ntoy;
g1=PI_2*PI_2*0.25/pow(sum1,2);
printf("g1=%lf \t",g1);
dg1=sqrt(pow(dl/0.25,2)+pow(2*dt/sum1,2));

//If l=0.45m
T_theory=PI_2*sqrt(0.45/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum2=sum2+T;
}
sum2=sum2/Ntoy;
g2=PI_2*PI_2*0.45/pow(sum2,2);
printf("g2=%lf \t",g2);
dg2=sqrt(pow(dl/0.45,2)+pow(2*dt/sum2,2));

//If l=0.65m
T_theory=PI_2*sqrt(0.65/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum3=sum3+T;
}
sum3=sum3/Ntoy;
g3=PI_2*PI_2*0.65/pow(sum3,2);
printf("g3=%lf \t",g3);
dg3=sqrt(pow(dl/0.65,2)+pow(2*dt/sum3,2));

//If l=0.85m
T_theory=PI_2*sqrt(0.85/g_theory);
for(i=0;i<Ntoy;i++)
{
	T=Gaussian(T_theory,dt);
	sum4=sum4+T;
}
sum4=sum4/Ntoy;
g4=PI_2*PI_2*0.85/pow(sum4,2);
printf("g4=%lf \n",g4);
dg4=sqrt(pow(dl/0.85,2)+pow(2*dt/sum4,2));

printf("T1=%lf \t T2=%lf \t T3=%lf \t T4=%lf \n",sum1,sum2,sum3,sum4);
g=(g1+g2+g3+g4)/4;
dg=sqrt(dg1*dg1+ dg2*dg2+ dg3*dg3+ dg4*dg4);
printf("Using the mean values g=%lf +- %lf \n",g,dg);

//least square fit y=A+Bx
l1=sqrt(0.25), l2=sqrt(0.45), l3=sqrt(0.65), l4=sqrt(0.85);

sumx=l1+l2+l3+l4;
sumx2=pow(l1,2)+pow(l2,2)+pow(l3,2)+pow(l4,2);
sumy=sum1+sum2+sum3+sum4;
sumxy=l1*sum1+l2*sum2+l3*sum3+l4*sum4;

D=Ntoy*sumx2-sumx*sumx;
A=(sumx2*sumy-sumx*sumxy)/D;
B=(Ntoy*sumxy-sumx*sumy)/D;

sumsy=pow(sum1-A-B*l1,2)+pow(sum2-A-B*l2,2)+pow(sum3-A-B*l3,2)+pow(sum4-A-B*l4,2);
sy=sqrt(sumsy/(Ntoy-2));
dA=sy*sqrt(sumx2/D);
dB=sy*sqrt(Ntoy/D);

gfit=pow(PI_2/B,2);
dgfit=dB/B;

printf("Using the Least Square linear fit g=%lf +- %lf \n",gfit,dgfit);
printf("A=%lf +- %lf \t B=%lf +- %lf \n",A,dA,B,dB);

return 0;}
