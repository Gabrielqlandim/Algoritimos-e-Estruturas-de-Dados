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
        novo->prox = *head;
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

 void multiplicacao(Node *head, Node *tail){
    if(head == NULL || head->prox == head){
        printf("Tamanho da lista é insuficiente :(");
    }
    else{
        int m = 0;
        do{
            
            if(head != tail){
                m = head->valor * head->prox->valor;
                printf("%d * %d = %d\n", head->valor, head->prox->valor, m);
                head = head->prox->prox;
            }
            else{
                m = head->valor * head->valor;
                printf("%d * %d = %d\n", head->valor, head->valor, m);
                head = head->prox;
            }
        }while(head != tail->prox);
    }
 }

 int main(void){
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    inserir(&head, &tail,1);
    inserir(&head, &tail,2);
    inserir(&head, &tail,3);

    multiplicacao(head, tail);
    return 0;
 }