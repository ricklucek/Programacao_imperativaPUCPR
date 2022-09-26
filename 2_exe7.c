#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int vector[10], i, j, *p, aux;

    for(i=0; i<10; i++){
        vector[i] = rand()%99 + 1;
    }
    printf("Vetor Gerado:\n");
    for(i=0; i<10; i++){
        printf("%d ", vector[i]);
    }

    //Função que joga os pares para o inicio do vetor
    for (int i = 0; i < 10; ++i) {
        if(vector[i] % 2 != 0){
            p = &vector[i];
            aux = *p;

            for(j=i; j<10; j++){
                p++;
                vector[j] = *p;
            }
            p = &vector[i];
            vector[10-i] = aux;

        }
    }
    printf("\n");
    printf("Novo Vetor:\n");
    for(i=0; i<10; i++){
        printf("%d ", vector[i]);
    }

}