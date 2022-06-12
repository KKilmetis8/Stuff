#include <stdio.h>
int main ()
{
int n,i,j,temp,flag,k;
scanf("%d",&n);
int A[n][n],A1[n][n],A2[n][n],A3[n][n];

for(i=0;i<n;++i)
{for(j=0;j<n;++j)
	{scanf("%d",&A[i][j]);
	}}

for(i=0;i<n;++i)
{for(j=0;j<n;++j)
	{A1[j][i]=A[i][j];
	}}
	
for(i=0;i<n;++i)
{for(j=0;j<n;++j)
	{
	temp=0;
	for(k=0;k<n;++k)
	{
	temp=temp+ A[i][k]*A1[k][j];
	}
A2[i][j]=temp;
}}

for(i=0;i<n;++i)
{for(j=0;j<n;++j)
	{
	temp=0;
	for(k=0;k<n;++k)
	{
	temp=temp+ A1[i][k]*A[k][j];
	}
A3[i][j]=temp;
}}

flag=1;
for(i=0;i<n;++i)
{for(j=0;j<n;++j)
	{if (A3[i][j]!=A2[i][j])
	 flag=0;
	 break;}	 
}
if (flag==1)
printf("yes");
else
printf("nope");
return 0;
}