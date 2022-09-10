#include <stdio.h>
int a, b, c, d=1;

int sequencia(){
    printf("digite o 1o valor: \n");
    scanf("%d", &a);
    printf("digite o 2o valor: \n");
    scanf("%d", &b);
    printf("digite o 3o valor: \n");
    scanf("%d", &c);

    if(c > b && b > a){
        return d = 0;
    }else {
        return d = 1;
    }
}

int main(){
    while(sequencia()){
        sequencia();
    }
    printf("media da sequencia: %d", (a+b+c)/3);

    return 0;
}