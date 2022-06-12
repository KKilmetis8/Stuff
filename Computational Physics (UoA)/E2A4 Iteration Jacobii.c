#include <stdio.h>
#include <math.h>

int main()
{
	double J[4][4],x[4],x1[4],max=0; 
	int i,j,k,counter=0;
int b[4]={-11,6,25,-11};
//We manually rearanged the rows until the given matrix was diagonially dominant
int A[4][4]={
	{8,0,-3,-1},
	{0,10,-1,2},
	{3,-1,11,-1},
	{0,2,-1,10}
	};
double invD[4][4]={
	{1/2,0,0,0},
	{0,-1/3,0,0},
	{0,0,1/2,0},
	{0,0,0,1/3}
	};
int I[4][4] = {
	{1,0,0,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,0,1}
	};
for(i=0;i<4;i++){
	for(j=0;j<4;j++){
		J[i][j]=0.0;
		for(k=0;k<4;k++)
J[i][j]=J[i][j]+invD[i][k]*A[k][j];}}

for(i=0;i<4;i++){
	for(j=0;j<4;j++){
J[i][j]=I[i][j]-J[i][j];
if (max<fabs(J[i][j]));
max=fabs(J[i][j]);
}}

if (max<1)
	printf("Jacobii method converges \n");

if (counter==0){
	for(i=0;i<4;i++){
	x[i]=0;
	x1[i]=0;}
	counter++;
}

for(i=0;i<100;i++){
x1[0]=(-A[0][1]*x[1]-A[0][2]*x[2]-A[0][3]*x[3]+b[0] ) * 1/A[0][0];
x1[1]=(-A[1][0]*x[0]-A[1][2]*x[2]-A[1][3]*x[3]+b[1] ) * 1/A[1][1];
x1[2]=(-A[2][0]*x[0]-A[2][1]*x[1]-A[2][3]*x[3]+b[2])  * 1/A[2][2];
x1[3]=(-A[3][0]*x[0]-A[3][1]*x[1]-A[3][2]*x[2]+b[3])  * 1/A[3][3];
	for(j=0;j<4;j++){
x[i]=x1[i];}}

printf("x1=%lf, x2=%lf, x3=%lf, x4=%lf",x1[0],x1[1],x1[2],x1[3]);
return 0;
}
