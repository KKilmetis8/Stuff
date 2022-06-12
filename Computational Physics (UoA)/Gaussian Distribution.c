#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

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