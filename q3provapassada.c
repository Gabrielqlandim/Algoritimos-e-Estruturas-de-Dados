#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *dir;
    struct Node *esq;
}Node;

void inserir(Node **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Node*)malloc(sizeof(Node));
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        (*raiz)->valor = n;
    }
    else if(n<(*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
}
int contaFolhas(Node *raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return contaFolhas(raiz->esq) + contaFolhas(raiz->dir);
}

int qtdFolhas(Node *raiz, int n){
    if(raiz == NULL)
        return 0;
    if(n<raiz->valor)
        return qtdFolhas(raiz->esq, n);
    else if(n>raiz->valor)
        return qtdFolhas(raiz->dir, n);
    return contaFolhas(raiz);
}

int main(void){
    system("CLS");
    Node *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);
    inserir(&raiz, 61);
    inserir(&raiz, 98);

    int quantidade = qtdFolhas(raiz, 48);

    printf("%d", quantidade);
    return 0;
}