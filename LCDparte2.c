#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inserir(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = NULL;
        novo->ant = NULL;
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            (*tail) ->prox = *head; 
            (*tail)->ant = *head;
        }
        else{
            novo->prox = *head;
            (*head)->ant = novo;
            *head = novo;
            (*tail)->prox = *head;
            (*head)->ant = *tail;
        }
    }
}

void inserirFinal(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        novo->ant = NULL;
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            (*tail)->prox = *head;
            (*tail)->ant = *head;
            (*head)->prox = *tail;
            (*head)->ant = *tail;
        }
        else{
            (*tail)->prox = novo;
            novo->ant = *tail;
            novo->prox = *head;
            (*head)->ant = novo;
            *tail = novo;
        }
    }
}

void inserirMeio(Node **head, Node **tail, int n, int ant){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = n;
        novo->prox = NULL;
        novo->ant = NULL;
        if(*head == NULL){
            inserir(&head, &tail, n);
        }
        else{
            Node *aux = *head;
            do{
                
                if(aux->valor == ant){
                    novo->prox = aux->prox;
                    novo->ant = aux;
                    aux->prox = novo;
                }
                aux = aux->prox;
            }while(aux != *head);
        }
    }
}

void remover (Node **head, Node **tail){
    if(*head == NULL){
        return;
    }
    else{
        if(*head == *tail){
            free(*head);
            *head = *tail = NULL;
        }
        else{
            Node *aux = *head;
            (*head) = (*head)->prox;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(aux);
        }
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head == NULL){
        return;
    }
    else{
        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;
        }
        else{
            Node *aux = *tail;
            (*tail) = (*tail)->ant;
            (*tail)->prox = *head;
            (*head)->ant = *tail;
            free(aux);
        }
    }
}

void removerMeio(Node **head, Node **tail, int ant){
    if(*head == NULL){
        return;
    }
    else{
        if(*head == *tail){
            free(*head);
            *head = *tail = NULL;
        }
        else{
            Node *aux = *head;
            while(aux->prox != *head && aux->valor != ant){
                aux = aux->prox;
            }
            if(aux->valor == ant){
                Node *temp = aux->prox;
                aux->prox = temp->prox;
                temp->ant = aux;

                if(temp==*tail){
                    *tail = aux;
                    
                }
                free(temp);
            }
        }
    }
}

int tamanho(Node *head, Node *tail){
    int cont = 0;
    do{
        head = head->prox;
        cont++;
    }while(head != tail->prox);
    return cont;
}
void imprimir(Node *head, Node *tail){
    do{
        printf("%d ", head->valor);
        head = head ->prox;
    }while(head != tail->prox);
    printf("\n");
}

int main(void){
    Node *head = NULL;
    Node *tail = NULL;

    inserir(&head, &tail, 9);
    removerFinal(&head, &tail);
    imprimir(head, tail);
    return 0;
}