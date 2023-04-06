#include <stdio.h>
#include <stdlib.h>

/*
    [ 0 | 1 | 
      1 | x |
      ...]
    coluna 0 - qual estado vai se ver 0
    coluna 1 - qual estado vai se ver 1 
    linha 0 - q0
    linha 1 - q1...
    */

int main(){
    int TAM, finais;
    printf("Digite o número de estados que o seu DFA terá\n");
    scanf("%d", &TAM);
    
    int tabela_transicao[TAM][2];

    printf("\nDigite a tabela de transição na seguinte formatação\n");
    printf(" ______\n| x  y |\n| z  w |\n|  ... |\n ⎻⎻⎻⎻⎻⎻\nx=estado quando q0 vê 0\ny=estado quando q0 vê 1\nz=estado quando q1 vê 0...\n\n");
    for(int i=0;i<TAM;i++){
        scanf("%d %d", &tabela_transicao[i][0], &tabela_transicao[i][1]);
    }

    printf("\nDigite quantos estados finais o seu DFA possui\n");
    scanf("%d", &finais);
    int estado_final[finais];
    
    printf("\nDigite os estados finais separados por espaços (sendo 0 para q0, 1 para q1, etc)\n");
    for(int i=0; i<finais;i++){
        scanf("%d", &estado_final[i]);
    }

    printf("\nDigite a string que você deseja verificar se faz parte da linguagem\n");
    char teste[10];
    scanf("%s", teste);

    int estado_atual=0;
    int it;

    for(int i=0;i<10;i++){ 
        it = teste[i]-'0';
        if(it==0 || it==1){
            estado_atual=tabela_transicao[estado_atual][it];
        }       
    }

    for(int i=0;i<finais;i++){
        if(estado_atual==estado_final[i]){
            printf("\n _____________\n|String aceita|\n ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻\n");
            break;
        }
        else{
            printf("\n _________________\n|String não aceita|\n ⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻\n");
            break;
        }
    }

    return 0;
}