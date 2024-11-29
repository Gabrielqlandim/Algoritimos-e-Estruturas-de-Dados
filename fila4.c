#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void inserir(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;
        
        if(*head == NULL){
            *head = novo;
        }
        else{
            Node *aux = *head;
            while(aux->prox !=NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

void remover(Node **head){
    if(*head == NULL){
        return;
    }
    else{
        Node *aux = *head;
        (*head) = (*head)->prox;
        free(aux);
    }
}
int tamanho(Node *head){
    Node *aux = head;
    int cont=0;
    while(aux!=NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

void imprimir(Node **head){
    Node *aux = *head;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}