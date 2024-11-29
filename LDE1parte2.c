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
        novo->valor=n;
        novo->prox=*head;
        novo->ant = NULL;
        if(*head == NULL){
            *head = novo;
        }
        else{
            novo->prox = *head;
            (*head)->ant = novo;
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
            if(novo->prox != NULL){
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
        (*head)->ant = NULL;
    }
}

void removerFinal(Node **head){
    if(*head == NULL){
        return;
    }
    else{
        Node *aux=*head;
        while(aux->prox->prox != NULL){
            aux = aux->prox;
        }
        free(aux->prox);
        aux->prox = NULL;
    }
}

void RemoverMeio(Node **head, int ant){
    if(*head == NULL){
        return;
    }
    else{
        if((*head)->valor == ant){
            Node *temp = *head;
            (*head)= (*head)->prox;
            if(*head !=NULL){
                (*head)->ant = NULL;
            }
            free(temp);
            return;
        }
        Node *aux = *head;
        while(aux->prox != NULL && aux->prox->valor != ant){
            aux = aux->prox;
        }
        if(aux->prox == NULL){
            return;
        }
        
        Node *temp = aux->prox;
        aux->prox = aux->prox->prox;
        if(aux->prox != NULL){
            aux->prox->ant = aux;
        }
        free(temp);
    }
}

void imprimir(Node *head){
    Node *aux=head;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main(void){
    system("cls");
    Node *head = NULL;
    inserir(&head, 10);
    imprimir(head);
    inserirFinal(&head, 45);
    imprimir(head);
    inserirMeio(&head, 20,10);
    imprimir(head);
    RemoverMeio(&head,20);
    imprimir(head);
    return 0;
}