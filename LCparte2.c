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
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            (*tail)->prox = *head;
        }
        else{
            novo->prox = *head;
            *head = novo;
            (*tail)->prox = *head;
        }
    }
}
void inserirFinal(Node **head, Node **tail, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = n;
        novo->prox = *head;
        if(*head == NULL){
            *head = *tail = novo;
            (*head)->prox = *tail;
            (*tail)->prox = *head;
        }
        else{ 
            (*tail)->prox = novo;
            (*tail) = novo;
            (*tail)->prox = *head;
        }
    }
}

void inserirMeio(Node **head, Node **tail, int n, int ant){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = n;
        novo->prox = NULL;
        if(*head == NULL){
            *head = *tail = novo;
            novo->prox = *head;
        }
        else{
            Node *aux = *head;
            do{
                if(aux->valor == ant){
                    novo->prox = aux->prox;
                    aux->prox = novo;
                }
                aux = aux->prox;
            }while(aux != *head);    
        }
    }
}

void imprimir(Node *head, Node *tail){
    do{
        printf("%d ", head->valor);
        head = head->prox;
    }while(head!=tail->prox);
    printf("\n");
}

int tamanho(Node *head, Node *tail){
    int cont = 0;
    if(head != NULL){
        do{
            head = head->prox;
            cont++;
        }while(head != tail->prox);
    }
    return cont;
}

void remover(Node **head, Node **tail){
    if(*head == NULL){
        return;
    }
    else if(*head == *tail){
        free(*head);
        *head = *tail = NULL;
    }
    else{
        Node *aux = *head;
        (*head) = (*head)->prox;
        (*tail)->prox = *head;
        free(aux);
    }
}

void removerMeio(Node **head, Node **tail, int n){
    if(*head == NULL){
        return;
    }
    else if((*head)->valor == n && (*head)->prox == *head){
        free(*head);
        *head = NULL;
        return;
    }
    else{
        Node *aux = *head;
        Node *temp = *head;
        if((*head)->valor == n){
            while(aux->prox != *head){
                aux = aux ->prox;
            }
            
            temp->prox = (*head)->prox;
            *head = (*head)->prox;
            free(temp);
            return;
        }
        else{
            Node *ant = temp;
            do{
                ant = temp;
                temp=temp->prox;
                if(temp->valor == n){
                    ant->prox = temp->prox;
                    free(temp);
                    return;
                }
            }while(temp != *head);
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
            *head = *tail = NULL;
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
}

int main(void){
    Node *head = NULL;
    Node *tail = NULL;

    inserir(&head, &tail, 1);
    inserir(&head, &tail, 2);
    inserir(&head, &tail, 3);
    imprimir(head, tail);
    printf("%d ", tamanho(head, tail));
    printf("\n");
    remover(&head, &tail);
    imprimir(head, tail);
    return 0;
}