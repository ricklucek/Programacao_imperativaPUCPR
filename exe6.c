#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

int main ()
{
    double x, y = 1.00, soma;
    printf("Digite o No de elementos da soma: \n");
    scanf("%lf", &x);

    while(y <= x){
        soma = soma + (y/ sqrt(y+2));
        y++;
    }

    printf("%f", soma);
}