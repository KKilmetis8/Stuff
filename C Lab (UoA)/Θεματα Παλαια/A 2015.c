#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
int N,M,K,z,j,i,a,b,c ;
double sum1,sum2,product,pro,arith,paran,ans;

pro=1.0;
sum1=0.0;
sum2=0.0;
product=1.0;
i=1;
j=1;
z=1;
printf("sum1=%lf \n",sum1);

printf("Give Value of N \n");
scanf("%d",&N);
printf("Give Value of M \n");
scanf("%d",&M);
printf("Give Value of K \n");
scanf("%d",&K);
printf("Give Value of a \n");
scanf("%d",&a);
printf("Give Value of b \n");
scanf("%d",&b);
printf("Give Value of c \n");
scanf("%d",&c);

printf("sum1=%lf \n",sum1); 
 
for(i=1; i<=N; i++)
{
j=1;
z=1;
		if (sum2!=0.0) 
		{sum2=sum2+product-sum1;}	
sum1=sum1+sum2;
product=1.0;
printf("sum1=%lf \n",sum1);
printf("mphka kai sto trito  loop o MAGAS :D\n " );
	for(j=1; j<=M; j++)
	{
	printf("mphka kai sto deftero loop :) \n" );
	if (product!=1.0)
	{sum2=sum2+product;}
	z=1;
	printf("sum2=%lf \n",sum2);
	product=1.0;
		for(z=1; z<=K; z++)
		{
		printf("den exo kanei tipota \n");
 		arith = a*z*z*j*j*j - b*i*i; 
		paran = z*z + c*j*j*j*j + i*i;
		pro = arith/paran;
		
		printf("z=%d,j=%d,i=%d pro=%lf \n",z,j,i,pro );
		product=product * pro;
		printf("product=%lf \n",product);
		printf("exo kanei pollaplasiasmo \n");
}}}

sum2=sum2+product-sum1;	
sum1=sum1+sum2;
printf("A= %lf", sum1);

return 0;
}