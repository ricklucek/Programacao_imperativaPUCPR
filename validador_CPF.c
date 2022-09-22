#include <stdio.h>
char cpf[12];
int i_cpf[12];
int i, primeirodigito, segundodigito, somador;
void le_cpf();
void primeiro_digito();
void vetor_inteiro_cpf();
void segundo_digito();
void valida();

int main(){

    le_cpf();
    vetor_inteiro_cpf();
    primeiro_digito();
    segundo_digito();
    valida();

    return 0;
}


//função que lê seu CPF
void le_cpf(){
    printf("Digite seu CPF:\n");

    scanf(" %s",cpf);
}

//Efetui a conversao de array de char para um array de int
void vetor_inteiro_cpf(){
    for(i=0; i<11; i++){
        i_cpf[i] = cpf[i] - 48;
    }
}

//Calcula o primeiro digito para o CPF
void primeiro_digito(){
    somador = 0;
    for(i=0; i<9; i++){
        somador = somador + i_cpf[i]*(10-i);
    }

    if(somador % 11 == 0 || somador % 11 == 1){
        primeirodigito = 0;
    }else{
        primeirodigito = 11 - somador% 11;
    }
}

//Calcula o segundo digito para o CPF
void segundo_digito(){
    somador = 0;
    for(i=0; i<10; i++){
        somador = somador + i_cpf[i]*(11-i);
    }

    if(somador % 11 == 0 || somador % 11 == 1){
        segundodigito = 0;
    }else{
        segundodigito = 11 - somador % 11;
    }
}


void valida(){
    if ((primeirodigito == i_cpf[9]) && (segundodigito == i_cpf[10])){
        printf("\nCPF VALIDADO!");
    }else{
        printf("\nCPF INVALIDO!");
    }
}