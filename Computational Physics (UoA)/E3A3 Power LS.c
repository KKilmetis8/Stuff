#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (){
double x[7]={1,2,2.5,4,6,8,8.5}, y[7]={0.4,0.7,0.8,1.0,1.2,1.3,1.4};
int i,j;
double sumlnylnx=0.0, sumlnx=0.0,sumlny=0.0, sumlnx2=0.0;
for(i=0;i<7;i++)
	{
	sumlny+=log(y[i]);
	sumlnx+=log(x[i]);
	sumlnylnx+=log(y[i])*log(x[i]);
	sumlnx2+=log(x[i])*log(x[i]);
	}
double a,b;
b= (7*sumlnylnx-sumlnx*sumlny)/(7*sumlnx2-sumlnx*sumlnx);
a= (sumlny-b*sumlnx)/7;
printf("\n LS Fitting: y=%lf x^%lf \n",exp(a),b); 
return 0;
}
