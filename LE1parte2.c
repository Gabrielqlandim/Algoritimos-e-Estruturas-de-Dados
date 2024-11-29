#include <stdio.h>
#include <stdlib.h>

typedef struct  Node{
    int valor;
    struct Node *prox;
}Node;

void inserir(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        if(*head == NULL){
            *head = novo;
        }
        else{
            novo->prox = *head;
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
                aux = aux ->prox;
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
            while(aux->prox != NULL && aux->valor != ant){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux ->prox = novo;
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
        while(aux->prox->prox!=NULL){
            aux = aux->prox;
        }
        free(aux->prox);
        aux->prox = NULL;
    }
}

void removerMeio(Node **head, int ant){
    if(*head == NULL){
        return;
    }
    else if((*head)->valor == ant){
        Node *aux = *head;
        (*head) = (*head)->prox;
        free(aux);
        
    }
    else{
        Node *aux = *head;
        while(aux->prox !=NULL && aux->prox->valor != ant){
            aux = aux->prox;
        }
        if(aux->prox != NULL){
            Node *temp = aux->prox;
            aux->prox = aux->prox->prox;
            free(temp);
        }
        
    }
}

void imprimir(Node *head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(void){
    system("cls");
    Node *head = NULL;
    inserir(&head, 15);
    inserir(&head, 100);
    inserirFinal(&head, 300);
    inserirMeio(&head, 5, 100);
    imprimir(head);
    //removerFinal(&head);
    removerMeio(&head, 5);
    imprimir(head);
    return 0;
}