#include <stdio.h>
#include <math.h>
int main ()
{
int i,j,z,n,m,k,a,b,c ;
double sum1,sum2,product;

do{
printf("Please give a,b,c,N,M,K \n");
scanf("%d %d %d %d %d %d",&a,&b,&c,&n,&m,&k);
}while((a<b) || (b<2) || (a<2) || (n<2) || (m<2) || (k<2) );

FILE *fp;
sum1=0.0;
sum2=0.0;
product=1.0;

for(i=1;i<=n;++i)
{
	for(j=1;j<=k;++j)
	{
		for(z=1;z<=m;++z)
		{
		sum2=sum2 + ( b*pow(j,3)*pow(i,5) - c*z*z)/(i*i + a*pow(j,4));
		}
	product=product*sum2;
	sum2=0.0;
	}
sum1=sum1+product;
product=1.0;
sum2=0.0;
}
printf("%lf",sum1);

fp=fopen("results_b1.dat","w");
fprintf(fp,"%lf \n %d \n %d \n %d \n %d \n %d \n %d \n",sum1,a,b,c,n,k,m);
fclose(fp);
return 0;
}