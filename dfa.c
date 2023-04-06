#include <stdio.h>
#include <stdlib.h>

/*
    [ 0 | 1 | 2| 
      1 | x | x|
      ...]
    coluna 0 - qual estado vai se ver 0
    coluna 1 - qual estado vai se ver 1 
    linha 0 - q0
    linha 1 - q1...
    */

int main(){
    int TAM, finais;
    printf("Digite o número de estados que o seu DFA terá considerando o alfabeto 0 e 1\n");
    scanf("%d", &TAM);
    
    int tabela_transicao[TAM][2];

    printf("Digite a tabela de transição (considerando a primeira linha sendo q0, segunda linha q1, etc):\nqual estado vai quando vê 0 - qual estado vai quando vê 1\n");
    for(int i=0;i<TAM;i++){
        scanf("%d %d", &tabela_transicao[i][0], &tabela_transicao[i][1]);
    }

    printf("Digite quantos estados finais o seu DFA possui\n");
    scanf("%d", &finais);
    int estado_final[finais];
    
    printf("Digite os estados finais separados por espaços (sendo 0 para q0, 1 para q1, etc)\n");
    for(int i=0; i<finais;i++){
        scanf("%d", &estado_final[i]);
    }

    printf("Digite a string que você deseja verificar se faz parte da linguagem\n");
    char teste[10];
    scanf("%s", teste);

    int estado_atual=0;
    int it;

    for(int i=0;i<10;i++){ 
        if(teste[i]=!NULL){
            it = teste[i]-'0';
            estado_atual=tabela_transicao[estado_atual][it];
            printf("entrou i:%d estado:%d it:%d\n", i, estado_atual, it);
        }       
    }

    /*printf("A tabela de transição digitado foi:");
    for(int i=0;i<TAM;i++){
        printf("\n");
        for(int j=0;j<2;j++){
            printf("%d ", tabela_transicao[i][j]);
        }
    }*/
    for(int i=0;i<finais;i++){
        if(estado_atual==estado_final[i]){
            printf("Linguagem aceita");
        }
    }

    return 0;
}