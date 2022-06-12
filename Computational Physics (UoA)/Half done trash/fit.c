#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

//Finds Determinant
double  det(double A[100][100], int n)
{
double Minor[100][100];
int i,j,k,c1,c2;
double determinant;
double c[100];
int O=1;
determinant = 0.0;
    {
    for(i = 0 ; i < n ; i++)
    {c1 = 0, c2 = 0;
		for(j = 0 ; j < n ; j++)
        {for(k = 0 ; k < n ; k++)
			{if(j != 0 && k != i)
				{Minor[c1][c2] = A[j][k];
                 c2++;
                    if(c2>n-2)
                    {c1++;
                     c2=0;
                    }
                }
            }
        }
    determinant = determinant + O*(A[0][i]*det(Minor,n-1));
    O=-1*O;
}}
return determinant;}

//A function that multiplies a 7x2 matrix with a 2x7 matrix
double **m7227(double a[7][2],double b[2][7]){
double pro[7][7]=(int *)malloc(c *sizeof(int) ,sum=0.0;
int i,j,k;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			sum=0.0;
			for(k=0;k<2;k++){
				sum=sum+a[i][k]*b[k][j]
			}
		pro[i][j]=sum;
		}
	}
return pro[7][7];}
		
//A function that finds the transpose of a 7x2 matrix
double **Tr72(double a[7][2]){  
double t[2][7]=(int *)malloc(c *sizeof(int);
int i,j;
for(i=0;i<7;i++){
	for(j=0;j<2;j++){
		t[j][i]=a[i][j]
}}
return t[2][7];
}

//Utilizing Gauss-Newton algorithm
int main ()
{
double x[7]={1,2,2.5,4,6,8,8.5}, y[7]={0.4,0.7,0.8,1.0,1.2,1.3,1.4},
double s=0.0,a=1.0,b=2.0,J[7][2],min=99999;
int i,j;

/*We want a curve of the form y=Ax^b
r=y-Ax^b
dr/da=-x^b
dr/db=-Ax^b * lnb */
		