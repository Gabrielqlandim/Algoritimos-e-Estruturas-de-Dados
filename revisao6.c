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
        novo->prox = NULL;

        if((*head)==NULL){
            *head = novo;
            *tail = novo;
        }
        else{
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void inserirPilha(Node **head, int n){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = n;
        novo->prox = *head;
        *head = novo;
    }
}

void concatenar(Node **head1, Node **tail1, Node **head2, Node **tail2) {
    if (*head1 == NULL) {  // Se a fila 1 está vazia, ela vira a fila 2
        *head1 = *head2;
        *tail1 = *tail2;
    } else if (*head2 != NULL) {  // Caso a fila 2 não esteja vazia
        (*tail1)->prox = *head2;  // Conecta a fila 1 com a fila 2
        *tail1 = *tail2;          // Atualiza o tail para o final da fila 2
    }else if(*head2 == NULL){
        *head2 = *head1;
        *tail2 = *tail1;
    }
    else{
        return;
    }
}

void pilha(Node *head, Node *topoPilha){
    Node *aux = head;

    while(aux!=NULL){
        inserirPilha(topoPilha, aux->valor);
        aux = aux->prox;
    }
}




int main(void){

    Node *head1 =NULL;
    Node *tail1=NULL;
    Node *head2 =NULL;
    Node *tail2=NULL;
    Node *topoPilha = NULL;
    inserir(&head1,&tail1,1);
    inserir(&head1,&tail1,2);
    inserir(&head2,&tail2,3);
    inserir(&head2,&tail2,4);
    
    concatenar(&head1,&tail1,&head2,&tail2);
    filaParaPilha(head1, &topoPilha);
    return 0;
}