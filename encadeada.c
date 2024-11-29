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
        novo->prox = *head;
        *head = novo;
        if(*head == NULL){
            *head = novo;
        }
    }
}

void inserirFinal(Node **head, int n){
     Node *novo = (Node*)malloc(sizeof(Node));
     if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
        }
        else{
            Node *aux = *head;

            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
     }
}

void inserirMeio(Node **head, int n, int ant){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        
        if(*head == NULL){
            novo->prox = NULL;
            *head = novo;
        }
        else{
            Node *aux = *head;
            while(aux->valor != ant && aux->prox != NULL){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
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

void removerFinal(Node **head){
    if(*head == NULL){
        return;
    }
    else if((*head)->prox == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        Node *aux = *head;

        while(aux->prox != NULL){
            aux = aux ->prox;
        }
        free(aux);
    }
}

void removerMeio(Node **head, int n){
    if(*head == NULL){
        return;
    }
    else if((*head)->valor==n){
        Node *aux = *head;
        (*head) = (*head)->prox;
        free(aux);
    }
    else{
        Node *aux = *head;

        while(aux->prox != NULL && aux->prox->valor != n){
            aux = aux->prox;
        }
        Node *temp = aux->prox;
        aux->prox = aux->prox->prox;
        free(temp);
        
        
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