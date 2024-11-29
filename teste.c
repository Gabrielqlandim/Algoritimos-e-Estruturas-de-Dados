#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;
Node* criarNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

Node* inserirOrdenado(Node* sorted, Node* novoNo) {
    // Caso especial: lista está vazia ou o novo nó deve ser inserido no início
    if (sorted == NULL || sorted->valor >= novoNo->valor) {
        novoNo->prox = sorted;
        return novoNo;
    }

    // Encontrar a posição correta para o novo nó
    Node* atual = sorted;
    while (atual->prox != NULL && atual->prox->valor < novoNo->valor) {
        atual = atual->prox;
    }

    // Inserir o novo nó na posição encontrada
    novoNo->prox = atual->prox;
    atual->prox = novoNo;

    return sorted;
}
Node* insertionSortListaEncadeada(Node* head) {
    Node* sorted = NULL; // Lista que vai armazenar os nós em ordem
    Node* atual = head;

    // Percorrer a lista original
    while (atual != NULL) {
        Node* proximo = atual->prox; // Armazena o próximo nó
        sorted = inserirOrdenado(sorted, atual); // Insere o nó atual na lista ordenada
        atual = proximo; // Avança para o próximo nó
    }

    return sorted; // Retorna a nova lista ordenada
}
void imprimirLista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}
int main() {
    // Criando a lista encadeada
    Node* head = criarNo(5);
    head->prox = criarNo(3);
    head->prox->prox = criarNo(8);
    head->prox->prox->prox = criarNo(1);
    head->prox->prox->prox->prox = criarNo(7);

    printf("Lista original:\n");
    imprimirLista(head);

    // Ordenando a lista usando Insertion Sort
    Node* sortedHead = insertionSortListaEncadeada(head);

    printf("\nLista ordenada:\n");
    imprimirLista(sortedHead);

    return 0;
}