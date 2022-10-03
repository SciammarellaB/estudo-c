#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TOP 64

typedef struct lista{
    int id;
    char nome[6];
    int idade;
}Lista;

int qtd = 0;
int max = 2;

Lista* incluir(Lista* vet){
    if(qtd == 0){
        vet = (Lista*) malloc(2 * sizeof(Lista));
        printf("\nMALLOC\n");
    }
    else if (qtd == max){
        vet = (Lista*) realloc(vet, 2 * max * sizeof(Lista));
        max = max * 2;
        printf("\nREALLOC\n");
    }
    vet[qtd].id = qtd+1;
    strcpy(vet[qtd].nome, "PESSOA");
    vet[qtd].idade = rand() % 71;
    qtd++;
    return vet;
}

void imprimir(Lista* vet, int qtd){
    int x=0;
    for(x=0; x < TOP; x++){
        printf("\nIndex: %d", vet[x].id);
        printf("\nNome: %s", vet[x].nome);
        printf("\nIdade: %d", vet[x].idade);
        printf("\n");
    }
}

int main(){
    Lista* vet = NULL;
    //CREATION
    int i = 0;
    for(i; i < TOP; i++){
        vet = incluir(vet);
    }
    //READING
    imprimir(vet, max);
    return 0;
}