#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inserir(Node **head, Node **tail, int n) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = n;
        if (*head == NULL) {
        *head = novo;
        *tail = novo;
        (*tail)->prox = *head;
        (*tail)->ant = *head;
        } else {
        novo->prox = *head;
        novo->ant = *tail;
        (*head)->ant = novo;
        (*tail)->prox = novo;
        *head = novo;
        }
    }
}

void sequencia(Node *head, Node *tail){
    int cont = 0;
    do{
        cont++;
        head = head->prox;
    }while(head!=tail->prox);

    if(cont<3){
        printf("void sequencia(Node *head, Node *tail)");
    }
    else{
        do{
            if(head->ant->valor %2 != 0 && head->ant->ant->valor %2 != 0 && head != tail->prox && head != tail->prox->prox){
                printf("%d\n", head->valor);
            }
            else if(head->prox->valor %2 != 0 && head->prox->prox->valor %2 != 0 && head->prox != tail && (head==tail->prox || head==tail->prox->prox)){
                printf("%d\n", head->valor);
            }
            head = head->prox;
        }while(head != tail->prox);
    }
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  inserir(&head, &tail, 12);
  inserir(&head, &tail, 11);
  inserir(&head, &tail, 3);
  inserir(&head, &tail, 10);
  sequencia(head, tail);
}