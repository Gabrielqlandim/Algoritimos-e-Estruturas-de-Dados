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
        
        if(*head != NULL){
            (*head)->ant = novo;
        }
        *head = novo;
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
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        novo->ant = aux;
        aux->prox = novo;
        }      
    }
}

void inserirMeio(Node **head, int n, int ant){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        novo->valor = n;
        novo->prox= NULL;
        novo->ant = NULL;

        if(*head==NULL){
            *head = novo;
        }
        else{
            Node *aux = *head;

            while(aux->prox != NULL && aux->valor != ant){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            novo->ant = aux;
            aux->prox = novo;
            if(novo->prox !=NULL){
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

            if(*head !=NULL){
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
void imprimir(Node *head){
    Node *aux = head;
    while(aux !=NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int tamanho(Node *head){
    Node *aux = head;
    int cont=0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
        
    }
    return cont;
}

int main(void){
    Node *head = NULL;
    
    inserir(&head, 10);
    imprimir(head);
    inserirFinal(&head, 45);
    imprimir(head);
    inserirMeio(&head, 20,10);
    imprimir(head);
    int a = tamanho(head);
    printf("%d", a);
    return 0;
}