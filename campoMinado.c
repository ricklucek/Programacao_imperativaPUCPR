#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int bomba; // 0 ou 1, que diz se a posição tem bomba ou nao
    int foiaberta; // 0 ou 1, que diz se a posição foi aberta ou nao
    int vizinhos; // 0 a 4, que diz quantas bombas há na vizinhança
}Campo;

int i, j, tam = 10, bombas=0;
Campo jogo[10][10];

// Zera todas as variáveis dentro do espaço delimitado pelo campo
void iniciaJogo(){
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            jogo[i][j].bomba = 0;
            jogo[i][j].foiaberta = 0;
            jogo[i][j].vizinhos = 0;

        }
    }
}

//Sorteia "n" bombas no campo
void sorteandoBombas(int n){
    srand(time(NULL));

    for (int k = 0; k < n; ++k) {
        i = rand() % 10;
        j = rand() % 10;

        if(jogo[i][j].bomba != 1){
            jogo[i][j].bomba = 1;
        }else{
            k--;
        }
    }
}

//verifica coordenadas
int verificaCoordenada(int i, int j){
    if(i>=0 && i<tam && j>=0 && j<tam){
        return 1;
    }else{
        return 0;
    }
}

//
int bombasVizinhas(int i,int j){
    /*
     * posição
     *    i-1
     *l-1      l+1
     *    i+1
    */
    int quantidade = 0;

    if(verificaCoordenada(i-1, j) && jogo[i-1][j].bomba == 1){
        quantidade++;
    }
    if(verificaCoordenada(i+1, j) && jogo[i+1][j].bomba == 1){
        quantidade++;
    }
    if(verificaCoordenada(i, j-1) && jogo[i][j-1].bomba == 1){
        quantidade++;
    }
    if(verificaCoordenada(i, j+1) && jogo[i][j+1].bomba == 1){
        quantidade++;
    }
    return quantidade;

}

//Procedimento para contar as bombas vizinhas
//função que retorna a quantidade de bombas na vizinhança de i j
void contarBombas(){
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j)
            jogo[i][j].vizinhos = bombasVizinhas(i,j);

    }
}

// Procedimento para imprimir o jogo
void imprimir(){

    printf("\n\n\t    ");
    for (int i = 0; i <tam ; ++i) {
        printf(" %d  ", i); //Indices das colunas
    }
    printf("\n\t   -----------------------------------------\n");
    for (int i = 0; i < tam; ++i) {
        printf(" \t%d  |",i); //indices das linhas
        for (int j = 0; j < tam; ++j){
            if(jogo[i][j].foiaberta){
                if(jogo[i][j].bomba){
                    printf(" * ");
                }else{
                    printf(" %d ", jogo[i][j].vizinhos);
                }
            }else{
                printf("   ");
            }
            printf("|");
        }
        printf("\n\t   -----------------------------------------\n");
    }
}
//Procedimento para abrir a posição digitada pelo usuário
void abrir(int i, int j) {
    if(verificaCoordenada(i, j) && jogo[i][j].foiaberta == 0){
        jogo[i][j].foiaberta = 1;
        if(jogo[i][j].vizinhos == 0){

            abrir(i-1,j);
            abrir(i+1,j);
            abrir(i,j+1);
            abrir(i,j-1);
        }
    }
}


// Função que retorna vitória (1) ou jogo em andamento(0)
int ganhou(){
    int qtde = 0;
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            if(jogo[i][j].foiaberta == 0 && jogo[i][j].bomba == 0){
                qtde++;
            }

        }
    }

    return qtde;
}

void jogar(){
    int linha, coluna;

    do {

        imprimir();
        do {
            printf("\nDigite as coordenadas linha e coluna: ");
            scanf("%d%d", &linha, &coluna);
        } while (verificaCoordenada(linha, coluna) == 0 || jogo[linha][coluna].foiaberta == 1);

        abrir(linha, coluna);
    } while (ganhou() != 0 && jogo[linha][coluna].bomba == 0);

    if(jogo[linha][coluna].bomba == 1){
        printf("\n\tFim de Jogo! Voce explodiu uma bomba\n");
    }else{
        printf("\n\tVocê conseguiu limpar o campo!\n");
    }
}

int main(){
    int opcao, n;
    do{
        iniciaJogo();
        do {
            printf("\nEscolha uma dificuldade: \n1-facil \n2-intermediário \n3-dificil\n ");
            scanf("%d", &n);
        } while (n>3 || n<=0);

        if(n==1){
            n = 10;
        }else if(n == 2){
            n=15;
        }else{
            n=20;
        }

        sorteandoBombas(n);
        contarBombas();
        printf("\n\t\t\tCampo Minado\n");
        jogar();

        printf("\nPressione 1 para jogar novamente: ");
        scanf("%d", &opcao);
    }while(opcao == 1);

}