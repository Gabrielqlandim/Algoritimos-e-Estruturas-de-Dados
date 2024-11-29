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

void inserirMeio(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
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

void inserirMeio(Node **head, int n, int pos){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        Node *aux =*head;
        Node *ant = NULL;
        novo->valor = n;
        
        if(pos==0 || *head == NULL){
            novo->prox = *head;
            *head = novo;
        } 
        else{
            int i=0;
            while(aux != NULL && i<pos){
                ant = aux;
                aux = aux->prox;
                i++;
            }
            ant->prox = novo;
            novo->prox = aux;
        }
    }
}

void remover(Node **head){
    Node *aux;
    while(*head != NULL){
        aux = *head;
        aux = aux->prox;
        free(aux);
    }
}

void removerNumero(Node **head, int n){
        Node *aux = *head;
        Node *ant;
        if(aux->valor == n){
            free(aux);
        }
        else{
            while(aux != NULL && aux->valor != n){
                ant = aux;
                aux = aux->prox;
            }
            
            ant->prox = aux->prox;
            free(aux);
        }       
}

void removerUltimo(Node **head){
    Node *aux = *head;
    Node *ant = NULL;
    if(aux->prox==NULL){
        free(aux);
        *head = NULL;
    }
    else{
        while(aux->prox!=NULL){
            ant = aux;
            aux = aux->prox;
        }
       
        ant->prox = NULL;
        free(aux);
    }
}

int tamanho(Node *head){
    int cont=0;
    while(head !=NULL){
        head = head->prox;
        cont++;
    }
    return cont;
}

void imprimir (Node *head){
    while(head != NULL){
        printf("%d", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(void){
    Node *head = NULL;
    return 0;
}