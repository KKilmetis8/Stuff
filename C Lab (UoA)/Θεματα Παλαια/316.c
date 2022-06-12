#include <stdio.h>

int main (void)
{
int met,n,i,j,z,k,flag;

printf("Hello World! \n");
printf("Input n>0,Integer \n");
scanf("%d",&n);

int prime[n];

if (n==0 || n==1)
{printf("Special case detected! There are no primes smaller than %d",n);
return 0;
}

if (n==2)
{printf("1,2");
return 0;}

if (n>=3)
{prime[0]=1;	
prime[1]=2;
k=1;}


for(j=3;j<=n; j++)
{
	flag=1;	
	for(i=2;i<j; i++)
	{
		if (j%i==0)
		{flag=0;	
	break;}}
if (flag==1)
{k=k+1;
prime[k]=j;}			
}

for(z=0;z<=k; z++)
{
printf( "%d, ", prime[z]);
}

return 0;
}