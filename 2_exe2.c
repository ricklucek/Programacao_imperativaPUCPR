#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int i, vector[10], n, times=0;
    for(i=0; i< 10; i++){   //Cria um vetor aleatório, de tamanho 10, entre 1 e 99
        vector[i] = rand() % 99 + 1;

    }
    for(i = 0; i< 10; i++){   //imprime o vetor criado
        printf("%i ", vector[i]);
    }
    printf("\n");

    printf("Digite um numero: \n");
    scanf("%d", &n);

    printf("Resultado encontrado: \n");

    for (i=0; i<10; i++){
        if(n == vector[i]){
            times ++;
            printf("posição: %d \n%d ", i,vector[i]);
        }

    }
    printf("\nTotal de ocorrência: %d", times);

    return 0;
}
