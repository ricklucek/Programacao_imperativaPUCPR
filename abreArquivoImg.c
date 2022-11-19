#include <stdio.h>
#include <stdlib.h>  // contém os protótipos para manipular arquivos

// em linhas gerais, para arquivos: abre, utiliza (lê ou grava), fecha
// o C permite efetuar estas operacoes usande caracteres (modo texto) ou bytes (modo binário)
// o programador que cria as funções de manipulação conforme seu modelo/necessidade/estrutura do arquivo

int main() {
    char arq[] = "02.ppm";  // nome do arquivo com caminho relativo
    // para caminho absulto, colocar o path completo
    // char arq[] = "C:\\Users\\Fulano\\Documents\\ppm\\05.ppm"
    // para representar a barra na string devemos colocar duas barras

    FILE *fp;  // ponteiro para arquivo

    char id[3];
    int colunas, linhas, maximo;
    unsigned char r, g, b;
    unsigned char rf, gf, bf;
    int i, j, k;
    int posicao;

    fp = fopen(arq, "rb"); // abrir arquivo para r - Read no modo b - Binario
    // ver página 254 da apostila do Backes sobre a combinação r, w, a, b para formatos
    if (fp == NULL) {  // retorna NULL se deu algum problema na abertura
        printf("Erro na abertura do arquivo <%s>", arq);
        exit(EXIT_FAILURE);  // sai com código de falha
    }

    fscanf (fp, "%s", id);        // identificador do formato PPM - P6
    fscanf (fp, "%d", &colunas);  // largura da imagem = total de colunas
    fscanf (fp, "%d", &linhas);   // altura da imagem = total de linhas
    fscanf (fp, "%d", &maximo);   // máximo de intensidade (neste trabalho, sempre 256)
    fscanf (fp, "%c", &r);        // consumir um quebra de linha no arquivo

    printf("Tipo do arquivo <%s>: %s\n", arq, id);
    printf("Maximo: %d\n", maximo);
    printf("Imagem tem %d x %d pixels\n", linhas, colunas);

    posicao = ftell(fp); // pegar a posicao fisica no arquivo anter de ler dados da imagem
    // lê o pixel 0,0 que é o pixel com a cor do fundo
    fscanf (fp, "%c%c%c", &rf, &gf, &bf);
    fseek(fp, posicao, SEEK_SET); // voltando ao início da imagem

    // na sequencia, para completar o programa

    // criar matriz dinâmica (calloc) do tamanho linha x coluna com sua estratégia de armazenar pixels/visitados
    // olhar no video do backes sobre alocação de matriz: https://programacaodescomplicada.wordpress.com/2012/11/09/aula-64-alocacao-dinamica-pt-6-alocacao-de-matrizes/

    // lendo os pixels da imagem, para cada pixel ler 3 valores, Red Green Blue (a cor em RGB)
    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            fscanf (fp, "%c%c%c", &r, &g, &b);
            if ((r!=rf) || (g!=gf)  || (b!=bf)  ){  // houve mudanca de cor em relacao ao fundo
                // colocar 1 na matriz alocada que de resto possue zeros devido ao calloc
                printf("x");  // aqui apenas estamos imprimindo na tela para 'ver' a imagem
            } else {  // não mexe
                printf("_");
            }
        }
        printf("\n");
    }
    fclose(fp);

    // criar a pilha que permite push e pop de coordenadas dos pixels vizinhos a serem analisados

    // achar a semente, o 1o.pixel diferente do fundo, fazendo uma varredura na matriz

        // analisar os 4 vizinhos da semente
        //   para cada vizinho diferente do fundo, coloca na pilha (push)
        //   faz pop e verificar os vizinhos
        //   qdo pilha estiver vazia, conta + 1 objeto

    // acabar de percorrer a imagem procurando por outras sementes
    // cuidado para não analisar o mesmo pixels diversas vezes

    return 0;
}
