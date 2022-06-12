#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,m,n;
    float x[10],a[10][10],b[10][10],u[10][10],c[10];
    printf("Enter the rank(n) of the given Matrix \n");
    scanf("%d",&n);
    printf("Enter the right hand side constants \n");
    for(i=0;i<n;i++)
    {scanf("%f",&a[i][n]);}
    printf("\n Enter the coefficients row wise \n");
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
        {scanf("%f",&a[i][j]);}}
    for(i=0;i<n;i++)
    {b[i][0]=a[i][0];}
    for(j=1;j<n+1;j++)
    {u[0][j]=(a[0][j]/b[0][0]);}
    for(m=1;m<n;m++)
    {for(i=m;i<n;i++){
      for(k=0;k<m;k++){
          a[i][m]=a[i][m]-b[i][k]*u[k][m];}
            b[i][m]=a[i][m];}
        for(j=m+1;j<n+1;j++){
            for(k=0;k<m;k++){
                a[m][j]=a[m][j]-b[m][k]*u[k][j];}
            u[m][j]=a[m][j]/b[m][m];}}
    for(k=0;k<n;k++)
    {i=(n-k-1);
	x[i]=u[i][n];
     for(j=i+1;j<n;j++)
	 {x[i]=x[i]-u[i][j]*x[j];}}
    printf("The solution is \n");
    for(i=0;i<n;i++)
    {printf("x[%d] = %f\n",i,x[i]);}
	double calc=0;
	calc=pow(n,3)/3 + pow(n,2) -n/3;
	printf("We did a total of %lf calculations",calc);
    return 0;}
