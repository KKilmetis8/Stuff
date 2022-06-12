#include <stdio.h>

int main ()
{
int i,j,k,n,flag;

printf("Hello World! \n");
printf("Please Input N \n");
scanf("%d",&n);

double A[n][n],B[n][n],AB[n][n],BA[n][n],temp;

for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
	printf("Please input the element A[%d][%d] \n",i,j);
	scanf("%lf",&A[i][j]);
	printf("A[%d][%d] %lf \n",i,j,A[i][j]);
}}
printf("Now inverting...\n");
for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
	B[i][j]=A[j][i];
	printf("B[%d][%d] %lf \n",i,j,B[i][j]);
}}
printf("Creating Matrixes AB,BA \n");
for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
	temp=0.0;
		for(k=0;k<n;++k)
		{temp=temp + A[i][k]*B[k][j];
		AB[i][j]=temp;
		}}}
for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
	temp=0.0;
		for(k=0;k<n;++k)
		{temp=temp + B[i][k]*A[k][j];
		BA[i][j]=temp;
		}}}
for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
	printf("AB[%d][%d] %lf \n",i,j,AB[i][j]);
	printf("BA[%d][%d] %lf \n",i,j,BA[i][j]);
	}}

flag=1;
for (i=0;i<n;++i)
{
	for(j=0;j<n;++j)
	{
		if(AB[i][j]*2 != AB[i][j]+BA[i][j])
		flag=0;
		break;
}}
if (flag==1)
{printf("AB=BA ARA ANTIMETATITHETE");}
else if (flag==0)
{printf("DEN ANTIMETATITHETE");}

return 0;
}

