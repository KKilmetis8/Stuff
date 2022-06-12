#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main (){

double sum=0.0, sum2=0.0, x=0.0, y=0.0, rndm=0.0;
double length=4.0;
int i, Ntoy=100000;

srand((unsigned)time(NULL));
rndm=((double)rand()/(double)RAND_MAX)* length;

for(i=0;i<Ntoy;i++){
	x=rndm;
	y=x*x*(1+exp(x*x));
	sum=sum+y;
	sum2=sum2+(y*y);
	rndm=((double)rand()/(double)RAND_MAX)* length;
	}
sum=sum/Ntoy;
sum2=sum2/Ntoy;

double error_sum=0.0, integral=0.0, error_integral=0.0;

error_sum=sqrt((sum2-(sum*sum))/Ntoy);
integral=sum*length*pow(10.0,-7.0); //*10^-7 for SI;
error_integral=error_sum*length*pow(10.0,-7.0);
printf("Without splitting the integral we have I=%lf +- %lf in SI units \n",integral, error_integral);

//Now we'll split the integral in two equal parts A from 0-2 and B from 2-4
double Asum=0.0, Asum2=0.0, suma=0.0, suma2=0.0,sumb=0.0, sumb2=0.0;
int Na=Ntoy/2;
rndm=(((double)rand()/(double)RAND_MAX)* length/2);
for(i=0;i<Na;i++){
	x=rndm;
	y=x*x*(1+exp(x*x));
	suma=suma+y;
	suma2=suma2+(y*y);
	rndm=(((double)rand()/(double)RAND_MAX)* length/2);
	}
rndm=(((double)rand()/(double)RAND_MAX)* length/2) +2;
for(i=0;i<Na;i++){
	x=rndm;
	y=x*x*(1+exp(x*x));
	sumb=sumb+y;
	sumb2=sumb2+(y*y);
	rndm=(((double)rand()/(double)RAND_MAX)* length/2) +2;
	}	
suma=suma/Na;
suma2=suma2/Na;
sumb=sumb/Na;
sumb2=sumb2/Na;

double Aerrsum=0.0, Aint=0.0, Aerrint=0.0;
Aerrsum=sqrt( suma2/Na- suma*suma/Na);
Aint=suma*length/2;
Aerrint=Aerrsum*length/2;

double Berrsum=0.0, Bint=0.0, Berrint=0.0;
Berrsum=sqrt( sumb2/Na- sumb*sumb/Na);
Bint=sumb*length/2;
Berrint=Berrsum*length/2;

integral=(Aint+Bint)*pow(10,-7);
error_integral=sqrt(Aerrint*Aerrint+Berrint*Berrint)*pow(10,-7);
printf("Splitting the integral in 2 we have I=%lf +- %lf in SI units \n",integral,error_integral);

//Now we'll split the integral in four equal parts A from 0-1, B from 1-2, C from 2-3 and D from 3-4
double Bsum=0.0, Bsum2=0.0, sumaa=0.0, sumaa2=0.0, sumbb=0.0, sumbb2=0.0, sumc=0.0, sumc2=0.0, sumd=0.0, sumd2=0.0;
int Nb;
rndm=(((double)rand()/(double)RAND_MAX)* length/4);
Nb=Ntoy/4;
for(i=0;i<Nb;i++){
	x=rndm;
	y=x*x*(1+exp(x*x));
	sumaa=sumaa+y;
	sumaa2=sumaa2+(y*y);
	rndm=(((double)rand()/(double)RAND_MAX)* length/4);
	}
for(i=0;i<Nb;i++){
	rndm=(((double)rand()/(double)RAND_MAX)* length/4) +1;
	x=rndm;
	y=x*x*(1+exp(x*x));
	sumbb=sumbb+y;
	sumbb2=sumbb2+(y*y);
	}
for(i=0;i<Nb;i++){
	rndm=(((double)rand()/(double)RAND_MAX)* length/4)+2;
	x=rndm;
	y=x*x*(1+exp(x*x));
	sumc=sumc+y;
	sumc2=sumc2+(y*y);	
	}
for(i=0;i<Nb;i++){
	rndm=(((double)rand()/(double)RAND_MAX)* length/4)+3;
	x=rndm;
	y=x*x*(1+exp(x*x));
	sumd=sumd+y;
	sumd2=sumd2+(y*y);
	}
sumaa=sumaa/Nb;
sumbb=sumbb/Nb;
sumc=sumc/Nb;
sumd=sumd/Nb;
sumaa2=sumaa2/Nb;
sumbb2=sumbb2/Nb;
sumc2=sumc2/Nb;
sumd2=sumd2/Nb;

Aerrsum=0.0, Aint=0.0, Aerrint=0.0;
Aerrsum=sqrt( (sumaa2-sumaa*sumaa)/Nb);
Aint=sumaa*length/4;
Aerrint=Aerrsum*length/4;

Berrsum=0.0, Bint=0.0, Berrint=0.0;
Berrsum=sqrt( (sumbb2-sumbb*sumbb)/Nb);
Bint=sumbb*length/4;
Berrint=Berrsum*length/4;

double Cerrsum=0.0, Cint=0.0, Cerrint=0.0;
Cerrsum=sqrt( (sumc2-sumc*sumc)/Nb);
Cint=sumc*length/4;
Cerrint=Cerrsum*length/4;

double Derrsum=0.0, Dint=0.0, Derrint=0.0;
Derrsum=sqrt( (sumd2-sumd*sumd)/Nb);
Dint=sumd*length/4;
Derrint=Derrsum*length/4;

integral=(Aint+Bint+Cint+Dint)*pow(10,-7);
error_integral=sqrt(Aerrint*Aerrint+Berrint*Berrint+Cerrint*Cerrint+Derrint*Derrint)*pow(10,-7);
printf("Splitting the integral in 4 we have I=%lf +- %lf in SI units \n",integral,error_integral);

return 0;
}
