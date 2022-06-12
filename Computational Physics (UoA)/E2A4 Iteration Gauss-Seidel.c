#include <stdio.h>
#include <math.h>

int main()
{
	double x[4],x1[4],GS[4][4],max=0; 
	int i=0,j=0,k=0,counter=0;
int b[4]={-11,6,25,-11};
//We manually rearanged the rows until the given matrix was diagonially dominant
int A[4][4]={
	{8,0,-3,-1},
	{0,10,-1,2},
	{3,-1,11,-1},
	{0,2,-1,10}
	};
int I[4][4] = {
	{1,0,0,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,0,1}
	};
double U[4][4]={
	{0,A[1][0],A[2][0],A[3][0]},
	{0,0,A[2][1],A[3][1]},
	{0,0,0,A[3][2]},
	{0,0,0,0}
	};
double L[4][4]={
	{0,0,0,0},
	{A[0][1],0,0,0},
	{A[0][2],A[1][2],0,0},
	{A[0][3],A[1][3],A[2][3],0}
	};
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
L[i][j]=I[i][j]-L[i][j];	
}}
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		GS[i][j]=0.0;
		for(k=0;k<4;k++)
		{			GS[i][j]=GS[i][j]+L[i][k]*U[k][j];
}}}
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		if (max<GS[i][j])
max=GS[i][j];}}
if (max<1)
	printf("Gauss-Seidel method converges \n");
if (counter==0){
	for(i=0;i<4;i++){
	x[i]=b[i];
	x1[i]=0;}
	counter++;
}

for(i=0;i<100;i++){
x1[0]=(-A[0][1]*x[1]-A[0][2]*x[2]-A[0][3]*x[3]+b[0] ) * 1/A[0][0];
x1[1]=(-A[1][0]*x1[0]-A[1][2]*x[2]-A[1][3]*x[3]+b[1] ) * 1/A[1][1];
x1[2]=(-A[2][0]*x1[0]-A[2][1]*x1[1]-A[2][3]*x[3]+b[2])  * 1/A[2][2];
x1[3]=(-A[3][0]*x1[0]-A[3][1]*x1[1]-A[3][2]*x1[2]+b[3])  * 1/A[3][3];

x[1]=x1[1];
x[2]=x1[2];
x[3]=x1[3];
}

printf("x1=%lf \n x2=%lf \n x3=%lf \n x4=%lf \n",x1[0],x1[1],x1[2],x1[3]);
return 0;}
