#include <stdio.h>
int main()
{
    double epitokio, kefalaio, tokos, axia_kef;
    int etos, plithos_eton;
    printf("\n Doste times gia kefalaio, plithos_eton, epitokio: ");
     printf("\n Xoriste tis times me kommata parakalo poly: ");
	scanf("%lf, %d, %lf", &kefalaio, &plithos_eton, &epitokio);
    axia_kef = kefalaio;
    for(etos = 1; etos<=plithos_eton; ++etos)
    {
        tokos = axia_kef * epitokio;
        axia_kef = tokos + axia_kef;
        printf("\n %d, %lf, %lf", etos, tokos, axia_kef);
    }
	return 0;
	}