#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));

    int i,vector[10], *p, *e, aux;

    //criando um vetor aleatório
    for(i=0; i<10; i++){
        vector[i] = rand()%99 + 1;
    }
    printf("Vetor criado\n");
    //imprime o vetor criado
    for(i=0; i<10; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    p = &vector[9];
    e = &vector;
    //invertendo as posições
    i=0;
    do {
        aux = *e;
        vector[i] = *p;
        vector[9-i]= aux;
        p--;
        e++;
        i++;
    }while(e < p);

    printf("vetor invertido \n");
    for(i=0; i<10; i++){
        printf("%d ", vector[i]);
    }
    return 0;
}
