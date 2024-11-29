#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void push(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        *head = novo;
        if(*head==NULL){
            *head = novo;
        }
    }
}

void pop(Node **head, int n){
    if(*head == NULL){
        return;
    }
    else{
        Node *aux = *head;
        aux = aux->prox;
        free(*head);
        *head = aux;
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