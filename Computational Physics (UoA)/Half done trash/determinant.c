#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int det(int A[100][100], int n)
{
    int Minor[100][100];
    int i,j,k,c1,c2;
    int determinant;
    int c[100];
    int O=1;
determinant = 0;
    {
        for(i = 0 ; i < n ; i++)
        {
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++)
            {
                for(k = 0 ; k < n ; k++)
                {
                    if(j != 0 && k != i)
                    {
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinant = determinant + O*(A[0][i]*det(Minor,n-1));
            O=-1*O;
        }
    }
    return determinant;
}