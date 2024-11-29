#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct { 
    char nome[30];  
    struct Node *prox; 
} Node;

void inserir(Node **head, Node **tail, char nome){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo!=NULL){
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
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

int buscar(Node *head, char nome){
    if(head == NULL){
        return;
    }
    else{
        Node *aux = head;
        int cont =1;

        while(aux->prox != NULL && strcmp(aux->nome, nome)!= 0){
            cont++;
            aux = aux->prox;
        }

        return cont;
    }
}




int main(void){
    Node *head = NULL;
    Node *tail = NULL;
    int cont = 0;
    int n = 0;

    while(n!=5){
        printf("Digite ai");
        scanf("%d", &n);
        if(n == 1){
            char nome[30];
            printf("Nome: ");
            scanf("%s", nome);
            inserir(&head,&tail,nome);
        }
        else if (n==2){
            
            remover(&head);
            cont ++;
        }
        else if(n==3){
            char nome[30];
            printf("Nome: ");
            scanf("%s", nome);
            printf("Paciente ta na posição: %d", buscar(head, nome));
        }
        else if(n==4){
            printf("%d", cont);
        }
        else if(n==5){
            break;
        }
        else{
            printf("Opcao invalida");
        }
    }
    return 0;
}