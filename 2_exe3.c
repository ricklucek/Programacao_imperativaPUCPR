#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int i, vLido[10], par=0, impar=0, vPar[10], vImpar[10];
    // Adiciona valores ao vLido e conta os valores pares e impares
    for(i=0; i<10; i++){
        vLido[i] = rand() % 99 + 1;

    }
    printf("Vetor Lido:\n");
    for(i=0; i<10; i++){
        printf("%d ", vLido[i]);
    }
    printf("\n");
    printf("\n");

    for(i=0; i<10; i++){
        if(vLido[i]%2 == 0){
            vPar[par] = vLido[i];
            par++;
        }else{
            vImpar[impar] = vLido[i];
            impar ++;
        }
    }
    printf("Vetor Par:\n");
    for(i=0; i<par; i++){
        printf("%d ", vPar[i]);
    }
    printf("\n");
    printf("\n");
    printf("Vetor Impar:\n");
    for(i=0; i<impar; i++){
        printf("%d ", vImpar[i]);
    }

    return 0;
}