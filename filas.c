#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void inserir(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;

        if((*head)==NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void remover(Node **head, Node **tail){
    Node *aux;
    if((*head) != NULL){
        aux = *head;
        *head = (*head)->prox;
        free(aux);
    }
    if((*head) == NULL){
        *tail = NULL;
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d", head->valor);
        head = head->prox;

    }
    printf("\n");
}

int tamanho(Node *head){
    int cont =0;

    while(head != NULL){
        head = head ->prox;
        cont ++;
    }
    return cont;
}


int main(void){
    Node *head = NULL;
    Node *tail = NULL;

    return 0;
}