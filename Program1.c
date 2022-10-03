#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista{
    int id;
    char nome[50];
    int idade;
}Lista;


int main(){
    Lista* vet = NULL;
    int qtd = 50;
    vet = (Lista*) malloc(qtd*sizeof(Lista));
    //CREATION
    int i=0;
    for(i=0; i < qtd; i++){
        vet[i].id = i+1;
        strcpy(vet[i].nome, "PESSOA");
        vet[i].idade = rand() % 71;
    }
    //READING
    int x=0;
    for(x=0; x < qtd; x++){
        printf("\nIndex: %d", vet[x].id);
        printf("\nNome: %s", vet[x].nome);
        printf("\nIdade: %d", vet[x].idade);
        printf("\n");
    }
    return 0;
}