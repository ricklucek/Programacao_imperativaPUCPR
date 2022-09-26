#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int i, j, matriz[5][5], somador;
void criaMatriz();
void somaValores();
void disp1();
void disp2();

int main(){
    srand(time(NULL));

    criaMatriz();
    printf("\n");
    somaValores();
    printf("\n");
    printf("\n");
    disp2();

    return 0;
    }


void criaMatriz(){ //função que cria uma matriz aleatória e mostra os valores dela
    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            matriz[i][j] = rand() % 99 +1;

            if(matriz[i][j] < 10){
                matriz[i][j] = 10;
            }
        }
    }

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void somaValores(){ //função que soma os valores de uma matriz
    somador = 0;
    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            somador = somador + matriz[i][j];
        }
    }

    printf("Soma dos elementos da matriz: %d", somador);
}

void disp1(){ //Mostra os elementos da matriz em cruz

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            if(j == 2){
                printf("%d ", matriz[i][j]);
            }else if(i == 2){
                printf("%d ", matriz[i][j]);
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }

}

void disp2(){   //Mostra os elementos nos extremos da matriz
    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            if(i == 0 || i == 4){
                printf("%d ", matriz[i][j]);
            } else if(j == 0 || j == 4){
                printf("%d ", matriz[i][j]);
            }else {
                printf("  ");
            }

        }
        printf("\n");
    }

}
