#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
int M,i,n ;

FILE *fp;
fp=fopen("randM.txt","w");

srand(time(NULL));
do
{
printf("input m");
scanf("%d",&M);
}
while(M<0);

for (i=1;i<=M; i++)
{
n=rand()%30 + 1;
fprintf(fp,"%d \n",n);
}

fclose(fp);
printf("All done now! :D");
return 0;
}