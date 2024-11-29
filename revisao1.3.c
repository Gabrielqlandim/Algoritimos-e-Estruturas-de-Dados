#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
} Node;

void inserir(Node **head, Node **tail, int valor){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;
        if (*head == NULL){
            *head = novo;
            *tail = novo;
        }else{
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void troca(Node **head1, Node **tail1, Node **head2, Node **tail2){
    if(*head1 == NULL && head2 == NULL){
        printf("Uma das filas esta vazia.\n");
        return;
    }
    else{
        Node *aux1 = *head1;
        Node *aux2 = *head2;

        *head1 = *head2;
        *head2 = aux1;

        Node *temp1 = aux1->prox;
        Node *temp2 = aux2->prox;
        (*head1)->prox = temp1;
        (*head2)->prox = temp2;

        if((*head1)->prox == NULL){
            *tail2 = *head1;
        }
        if((*head2)->prox == NULL){
            *tail1 = *head2;
        }
    }
}
void printQueue(Node *head){
    while (head != NULL) {
        printf("%d ", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(){
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    inserir(&head1, &tail1, 1);
    inserir(&head1, &tail1, 20);
    inserir(&head1, &tail1, 29);
    
    inserir(&head2, &tail2, 3);
    inserir(&head2, &tail2, 14);

    printf("Antes da troca:\n");
    printf("Fila01: ");
    printQueue(head1);
    printf("Fila02: ");
    printQueue(head2);

    // Chamando a função troca
    troca(&head1, &tail1, &head2, &tail2);

    printf("\nDepois da troca:\n");
    printf("Fila01: ");
    printQueue(head1);
    printf("Fila02: ");
    printQueue(head2);

    return 0;
}