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
    }
}

void inserirMeio(Node **head, int n, int pos){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        if((*head) == NULL || pos ==0){
        
        novo->prox = *head;
        *head = novo;
        }
    }
    
    else{
        Node *aux = *head;
        Node *ant = NULL;
        int i=0;

        while(aux != NULL || i<pos){
            ant = aux;
            aux = aux->prox;
            i++;
        }
        ant->prox = novo;
        novo->prox = aux;
    }
}


void inserirFinal(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;
        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void Remover(Node **head){
    Node *aux;
    while((*head) != NULL){
        aux = *head;
        (*head) = (*head)->prox;
        free(aux);
    }
}

void removerFinal(Node **head, Node **tail){
    Node *aux = *head;
    Node *ant= NULL;

    while(aux->prox != NULL){
        ant = aux;
        aux=aux->prox;
    }
    if(aux->prox == NULL){
        free(aux);
        *head = NULL;
        *tail = NULL;
    }
    free(aux);
    ant->prox = NULL;
    *tail = ant;
}

void removerMeio(Node **head, Node **tail, int n){
    Node *aux = *head;
    Node *ant = NULL;
    while(aux != NULL || aux -> valor != n){
        ant = aux;
        aux = aux->prox;
    }
    if(aux != NULL){

        if(aux == *head){
            *head = aux->prox;
        }
        else{
            ant->prox = aux->prox;
        }
        if(aux == *tail){
        *tail = ant;
        }
        free(aux);
    }
}