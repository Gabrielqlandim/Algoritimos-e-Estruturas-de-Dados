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
        inserir(&(*raiz)->esq , n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
}

void inOrdem(Node *raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

/*void posOrdem(Node *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}*/

int main(void){
    Node *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);
    inserir(&raiz, 61);
    inserir(&raiz, 98);

    inOrdem(raiz);
    return 0;
}