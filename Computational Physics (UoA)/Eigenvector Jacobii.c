#include <stdio.h>
#include <math.h>

double sign (double x)
{
	double s;
	s=x/fabs(x);
	return s;
}

int main (void)
{
double costheta,sintheta,check;
double pinakas[3][3],max=0.0, pinakas_s1[3][3],sum=0.0,alpha=0.0,beta=0.0;
int i,j,r=12,q=12,counter=0;

pinakas[0][0]=2.0;  pinakas[0][1]=-1.0; pinakas[0][2]=10.0; pinakas[0][3]=0.0; //pinakas[0][4]=-11.0; 
pinakas[1][0]=0.0;  pinakas[1][1]=-3.0; pinakas[1][2]=-1.0; pinakas[1][3]=8.0; //pinakas[1][4]=11.0; 
pinakas[2][0]=10.0; pinakas[2][1]=-1.0; pinakas[2][2]=2.0;  pinakas[2][3]=0.0; //pinakas[2][4]=6.0; 
pinakas[3][0]=-1.0; pinakas[3][1]=11.0; pinakas[3][2]=-1.0; pinakas[3][3]=3.0; //pinakas[3][4]=25.0; 
do{
if (counter>0)
{for (i=0;i<4;i++)
	{for (j=0;j<4;j++){
pinakas[i][j]=pinakas_s1[i][j];}}}

	for (i=0;i<4;i++)
	{	for (j=0;j<4;j++)
		{	if ( fabs(max)<fabs(pinakas[i][j]) )
			{		max=pinakas[i][j];
					r=i;
					q=j;
	}	}	}		
printf("max=%lf \n",max);

beta=fabs(pinakas[q][q]-pinakas[r][r]);
alpha=2*pinakas[r][q]*sign( pinakas[q][q]-pinakas[r][r]);

costheta=sqrt( 0.5*(1+ beta/sqrt(alpha*alpha+beta*beta)));
sintheta=alpha/(2*costheta*sqrt(alpha*alpha+beta*beta));
printf("b=%lf,a=%lf,cos=%lf,sin=%lf,r=%d,q=%d \n",beta,alpha,costheta,sintheta,r,q);	

for (i=0;i<4;i++)
{for (j=0;j<4;j++)
	{
		if ( i!=q && i!=r && j!=q && j!=r )
			{pinakas_s1[i][j]=pinakas[i][j];}
		if ( i!=q && i!=r ){
		pinakas_s1[i][r]=pinakas[i][r]*costheta-pinakas[i][q]*sintheta;
		pinakas_s1[r][i]=pinakas[i][r]*costheta-pinakas[i][q]*sintheta;
		}
}}


pinakas_s1[r][r]=pinakas[r][r]*costheta*costheta+pinakas[q][q]*sintheta*sintheta-2*pinakas[r][q]*sintheta*costheta;
pinakas_s1[q][q]=pinakas[r][r]*sintheta*sintheta+pinakas[q][q]*costheta*costheta+2*pinakas[r][q]*sintheta*costheta;
pinakas_s1[r][q]=0;
pinakas_s1[q][r]=0;

check=fabs( sintheta*sintheta+costheta*costheta-1);
printf("check=%lf \n",check);

for (i=0;i<4;i++){
	for (j=0;j<4;j++){
	if (i!=j)
		sum=pow(fabs(pinakas_s1[i][j]),2)+sum;
}}
counter++;
}while (sum<0.001);
	
printf("l1=%lf \t l2=%lf \t l3=%lf \t l4=%lf \n",pinakas_s1[0][0],pinakas_s1[1][1],pinakas_s1[2][2],pinakas_s1[3][3]);

double x1,x2,x3,x4;
x1=-11.0/pinakas_s1[0][0];
x2=-11.0/pinakas_s1[1][1];
x3=6.0/pinakas_s1[2][2];
x4=25.0/pinakas_s1[3][3];
printf("x1=%lf \t x2=%lf \t x3=%lf \t x4=%lf \n",x1,x2,x3,x4);
printf("Iterations needed %d",counter);
return 0;}
