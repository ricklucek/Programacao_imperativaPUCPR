#include <stdio.h>

int main () {
    int n1, n2, maior_valor;
    n2 = 1;

    while(n2 != 0 || maior_valor == 0){
        printf("Insira um valor: \n");
        scanf("%d", &n1);
        n2 = 1;

        if(n1 == 0){
            n2 = n1;
        }
        if(n1 % 2 != 0 && n1 > maior_valor){
            maior_valor = n1;
        }
    }
    printf("Maior valor impar: %d", maior_valor);
    return 0;
}

