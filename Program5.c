#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pessoa{
	char nome[50];
	int idade;
}Pessoa;

typedef struct lista{
    int id;
	Pessoa* pessoa;
}Lista;

int qtd = 0;
int max = 2;

//CRIAR O MALLOC PARA A PESSOA
Pessoa** incluir_pessoa(){
	return (Pessoa**) malloc(sizeof(Pessoa));
}

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
    vet[qtd].id = qtd + 1;
    vet[qtd].pessoa = incluir_pessoa();
    strcpy(vet[qtd].pessoa->nome, nome);
    vet[qtd].pessoa->idade = idade;
    qtd++;
    return vet;
}

void imprimir(Lista* vet, int qtd){
    int x = 0;
    for(x = 0; x < qtd; x++){
    	printf("\nPonteiro vet: %d", &vet);
        printf("\nIndex: %d", vet[x].id);
        printf("\nPonteiro pessoa: %d", vet[x].pessoa);
        printf("\nNome: %s", vet[x].pessoa->nome);
        printf("\nIdade: %d", vet[x].pessoa->idade);
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
                
                printf("\nNome?");
                char nome[50];
                scanf("\n%s", nome);
                printf("\nIdade?");
                int idade;
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
