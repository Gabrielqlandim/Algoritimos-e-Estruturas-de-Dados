#include <stdio.h>
#include <stdlib.h>
//altura
typedef struct Node{
    int valor;
    struct Node *esq;
    struct Node *dir;
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
int altura(Node *raiz){
    if(raiz == NULL)
        return -1;
    else{
        int ae = altura(raiz->esq);
        int ad = altura(raiz->dir);
        return 1+(ae>ad?ae:ad);
    }
}

int main(void){
    Node *raiz = NULL;
    inserir(&raiz, 23);
    inserir(&raiz, 15);
    inserir(&raiz, 42);
    inserir(&raiz, 7);
    inserir(&raiz, 31);
    inserir(&raiz, 61);
    inserir(&raiz, 98);
    inserir(&raiz, 100);
    inserir(&raiz, 1);
    inserir(&raiz, 2);
    inserir(&raiz, 3);

    printf("%d ", altura(raiz));
    return 0;
}