#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void inserir(Node **head, int v){
    Node *novo = (Node*)malloc(sizeof(Node));
        if(novo!=NULL){
            novo->valor = v;
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
    inserir(&head, 3);
    inserir(&head, 2);
    imprimir(head);
    remover(&head);
    imprimir(head);
    return 0;
}