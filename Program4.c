#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista{
    int id;
    char nome[50];
    int idade;
}Lista;

int qtd = 0;
int max = 2;

Lista* incluir(Lista* vet, char nome[50], int idade){
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
    strcpy(vet[qtd].nome, nome);
    vet[qtd].idade = idade;
    qtd++;
    return vet;
}

void imprimir(Lista* vet, int qtd){
    int x=0;
    for(x=0; x < qtd; x++){
        printf("\nIndex: %d", vet[x].id);
        printf("\nNome: %s", vet[x].nome);
        printf("\nIdade: %d", vet[x].idade);
        printf("\n");
    }
}

int main(){
    Lista* vet = NULL;
    int stop = 1;
    int opcao = -1;
    
    printf("\nINICIALIZANDO\n");
    
    do{
        printf("\n1. Incluir");
        printf("\n2. Listar");
        printf("\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                char nome[50];
                int idade;

                printf("\nNome?");
                scanf("\n%s", nome);
                printf("\nIdade?");
                scanf("\n%d", &idade);
                vet = incluir(vet, nome, idade);

                //SAIR
                printf("\nSair ?");
                printf("\n0. SIM");
                printf("\n1. NAO");
                printf("\n");
                scanf("%d",&stop);
                break;
            case 2:
                printf("\nIMPRIMINDO\n");
                imprimir(vet, qtd);
                //SAIR
                printf("\nSair ?");
                printf("\n0. SIM");
                printf("\n1. NAO");
                printf("\n");
                scanf("%d",&stop);
                break;
        }
    }while(stop);
    return 0;
}