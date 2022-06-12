#include <stdio.h>
int main ()
{
int n,i,j,sum;
sum=0;
scanf("%d",&n);
for(i=2;i<n;++i)
{
sum=0;
	for(j=1;j<=i;++j)
	{
	if( (i%j) ==0)
	{sum=sum+j;}
	}
if(sum==2*i)
{printf("%d \t",i);}
}
return 0;
}