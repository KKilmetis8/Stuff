#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//Variables
int year;

char endchar;

//Main Body
printf("\n hello world!");
printf("\n Give a year to check if it's a leap year");
scanf("%d", &year);

	if ( year%400 == 0 )
{
	printf("\n The year %d is a leap year", year);
}
	else if ( year%100 == 0 )
{
	printf("\n The year %d is NOT a leap year", year);
}
	else if ( year%4 == 0 )
{	
	printf("\n The year %d is a leap year", year);
}
	else
{
	printf("\n The year %d is NOT a leap year", year);
}

 system("pause");  
   return 0;
}