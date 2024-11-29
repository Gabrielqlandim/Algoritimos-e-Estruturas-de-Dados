#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {  
    char nome[30]; 
    struct Node *prox;
}  Node ;

void push(Node **head, char nome[]){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        if(*head == NULL){
            *head = novo;
        }
        else{
            novo->prox = *head;
            *head = novo;
        }
    }
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    }
    else{
        Node *aux = head;

        while(aux != NULL){
            aux = aux->prox;
        }
        printf("%s", aux->nome);
    }
}

void imprimirPar(Node *head){
    if(head == NULL){
        return;
    }
    else{
        Node *aux = head;
        int cont =1;
        while(aux!= NULL){
            if(cont%2==0){
                printf("%s", aux->nome);
            }
            aux = aux->prox;
        }
    }
}

int main() {
    Node *topo = NULL;
    int opcao;
    char nome[30];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir aluno na pilha\n");
        printf("2. Imprimir a base da pilha\n");
        printf("3. Imprimir nós nas posições pares\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do aluno: ");
                scanf("%s", nome);
                push(&topo, nome);
                break;
            case 2:
                imprimir(topo);
                break;
            case 3:
                imprimirPar(topo);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}