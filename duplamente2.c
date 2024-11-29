#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inserir(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        novo->ant = NULL;
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
        novo->ant = NULL;
        if(*head == NULL){
            *head = novo;
        }
        else{
            Node *aux = *head;

            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->ant = aux;
        }
    }
}

void inserirMeio(Node **head, int n, int ant){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;
        novo->ant = NULL;

        if(*head == NULL){
            *head = novo;
        }
        else{
            Node *aux = *head;

            while(aux->prox != NULL && aux->valor != ant){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
            if(aux->prox !=NULL){
                //novo->prox = aux->prox; pode ta aq tbm
                aux->prox->ant = novo;
            }

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
    else{
        Node *aux = *head;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        free(aux);
    }
}

void removerMeio(Node **head, int n){
    if(*head == NULL){
        return;
    }
    else{
        if((*head)->valor == n){
            Node *temp = *head;
            (*head) = (*head)->prox;
            if(*head != NULL){
                (*head)->ant = NULL;
            }
            free(temp);
            return;
        }
        Node *aux = *head;

        while(aux->prox != NULL && aux->prox->valor != n){
            aux = aux->prox;
        }
        Node *temp = aux->prox;
        aux->prox = aux->prox->prox;
        aux->prox->ant = aux;
        free(temp);
        

    }
}

int tamanho(Node *head){
    Node *aux = head;
    int cont=0;

    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

void imprimir (Node *head){
    Node *aux = head;

    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

