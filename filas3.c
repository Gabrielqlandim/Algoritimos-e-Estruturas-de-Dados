#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void Inserir(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;

        if((*head) == NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void Remover(Node **head, Node **tail){

    Node *aux;
    while((*head)!= NULL){
        aux = *head;
        (*head)= (*head)->prox;
        free(aux);
    }

}

void RemoverEspecifico(Node **head, Node **tail, int n){
    Node *aux;
    Node *ant = NULL;
    if((*head) == NULL || (*head)->valor == n){
        aux=*head;
        (*head) = (*head)->prox;
        if(*head == NULL){
            *tail = NULL;
        }
        free(aux);
    }

    else{
        aux = *head;
        while(aux != NULL || aux->valor != n){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->prox == NULL){
            *tail = ant;
        }
        ant->prox = aux ->prox;
        free(aux);
    }
}

int tamanho(Node *head){
    int cont = 0;
    while(head != NULL){
        head = head->prox;
        cont ++;
    }
    return cont;
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main (void){
    Node *head = NULL;
    Node *tail = NULL;
    return 0;
}