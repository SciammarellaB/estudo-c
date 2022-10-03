#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista{
    int id;
    char nome[6];
    int idade;
}Lista;


int main(){
    Lista* vet = NULL;
    int qtd = 0;
    int max = 2;
    //CREATION
    int i = 0;
    for(i; i < 16; i++){
        if(qtd == 0){
            vet = (Lista*) malloc(2 * sizeof(Lista));
            printf("\nMALLOC\n");
        }
        else if (qtd == max){
            vet = (Lista*) realloc(vet, 2 * max * sizeof(Lista));
            max = max * 2;
            printf("\nREALLOC\n");
        }
        vet[i].id = i+1;
        strcpy(vet[i].nome, "PESSOA");
        vet[i].idade = rand() % 71;
        qtd++;
    }
    //READING
    int x=0;
    for(x=0; x < 16; x++){
        printf("\nIndex: %d", vet[x].id);
        printf("\nNome: %s", vet[x].nome);
        printf("\nIdade: %d", vet[x].idade);
        printf("\n");
    }
    return 0;
}