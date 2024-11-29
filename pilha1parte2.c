#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void inserir(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = n;
        novo->prox = *head;
        *head = novo;
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

void imprimir(Node *head){
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(void){
    Node *head = NULL;
    inserir(&head, 10);
    inserir(&head, 45);
    imprimir(head);
    remover(&head);
    imprimir(head);
    return 0;
}