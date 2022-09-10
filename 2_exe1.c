#define MAX 10

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int i, vector[10], inverted[10], *p, **aux;
    for(i=0; i< MAX; i++){   //Cria um vetor aleatório, de tamanho 10, entre 1 e 99
        vector[i] = rand() % 99 + 1;

    }
    p = vector;
    for(i = 0; i< MAX; i++){   //imprime o vetor criado
        printf("%i ", vector[i]);
    }
    printf("\n");

    for (i = 0; i < MAX; i++){     //inventendo as posições do vetor
        aux = p;
        p++;
        inverted[9-i] = *aux;
    }

    printf("Novo vetor: \n");
    for(i = 0; i< MAX; i++){   //imprime o novo vetor
        printf("%d ", inverted[i]);
    }

}
