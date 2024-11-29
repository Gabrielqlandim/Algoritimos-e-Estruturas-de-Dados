#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void Inserir(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!= NULL){
        novo->valor = n;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            novo->prox = *head;
            *head = novo;
        }
        (*tail)->prox = *head;
    }
}

void inserirFinal(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
        }
        else{
            (*tail)->prox = novo;
            novo->prox = *head;
            *tail = novo;

        }
    }
}

void inserirMeio(Node **head, Node **tail, int n, int suc){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        if(*head==NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
        }
        else{
            Node *aux = *head;
            while(aux->prox != *head && aux->valor != suc){
                aux = aux ->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            (*tail)->prox = *head;
            if(aux==*tail){
                *tail = novo;
            }
        }
    }
}

void remover(Node **head, Node **tail){
    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
        return;
    }
    else{
        Node *aux = *head;
        (*head) = (*head)->prox;
        (*tail)->prox = *head;
        free(aux);
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head == *tail){
        *head = NULL;
        *tail =NULL;
    }
    else{
        Node *aux = *head;

        while(aux->prox != *tail){
            aux = aux->prox;
        }
        free(*tail);
        *tail = aux;
        (*tail)->prox = *head;
    }
}

void removerMeio(Node **head, Node **tail, int n){
    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
    }
    else{
        if((*head)->valor == n){
            Node *temp = *head;
            *head = (*head)->prox;
            (*tail)->prox = *head;
            free(temp);
            return;
        }
        Node *aux = *head;

        while(aux->prox != *head && aux->prox->valor != n){
            aux = aux->prox;
        }
        Node *temp = aux->prox;
        aux->prox = temp->prox;

        if(temp == *tail){
            *tail = aux;
        }
        free(temp);

    }
}

int tamanho(Node *head, Node *tail){
    int cont = 0;
    if(head!=NULL){
        do{
            head = head->prox;
            cont++;
        }while(head != tail->prox);
    }
    return cont;
}

void imprimir(Node *head, Node *tail){
    
    do{
        printf("%d ", head->valor);
        head = head->prox;
    }while(head != tail->prox);
}