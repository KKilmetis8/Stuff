#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double p (double x){
	double d=0.0;
	d=pow(x,2)+pow(x,5)+pow(x,6);
	return d;
}

double p2 (double x){
	double t=0.0;
	t=2+20*pow(t,3)+30*pow(t,4);
	return t;
}

double p4 (double x){
	double m=0.0;
	m=2+120*m+360*m*m;
	return m;
}
 int main(void)
 {
 	//Trapezoidal
 	int N,i;
 	double h,integral=0.0,sum=0.0,truevalue=31.619;
 	N=100;
 	h=(2.0-0.0)/N;
 	double x[N];
 	for(i=0;i<N;i++){
 		x[i]=i*h;
 		sum+=p(x[i]);
 	}
 	integral=(h/2)*(p(0)+2*sum+p(2));
 	printf("\n Using the trapezoidal rule ,I=%lf",integral);
 	double accuracy=fabs(integral-truevalue)/truevalue;
 	accuracy=accuracy*100;
 	printf("\n Accuracy Error %lf percent",accuracy);
 	double error=2*h*h*p2(2)/12;
 	printf("\n Error %lf",error);
 	//Simpson's Rule
 	double integral2=0.0,oddsum=0.0,evensum=0.0;
 	for(i=0;i<N;i++){
 		evensum+=2*p(x[i]);
 		i++;
 	}
 	for(i=1;i<N;i++){
 		oddsum+=4*p(x[i]);
 		i++;
 	}
 	printf("\n oddsum= %lf \t evensum= %lf", oddsum,evensum);
 	integral2=p(0.0)+p(2.0)+oddsum+evensum;
 	integral2=h*integral2/3.0;
 	printf("\n Using Simpson's Rule of 1/3 ,I=%lf",integral2);
 	double accuracy2=fabs(integral2-truevalue)/truevalue;
 	accuracy2=accuracy2*100;
 	printf("\n Accuracy Error %lf percent",accuracy2);
 	double error2=2*pow(h,4)*p4(2)/180;
 	printf("\n Error %lf",error2);
 	return 0;
 }