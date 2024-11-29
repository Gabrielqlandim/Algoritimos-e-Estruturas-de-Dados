#include <stdio.h>
#include <stdlib.h>
//maior
typedef struct Node{
    int valor;
    struct Node *dir;
    struct Node *esq;
}Node;

void inserir(Node **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Node*)malloc(sizeof(Node));
        (*raiz)->dir= NULL;
        (*raiz)->esq=NULL;
        (*raiz)->valor = n;
    }
    else if(n<(*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        inserir(&(*raiz)->dir, n);
}
int maior(Node *raiz){
    if(raiz == NULL)    
        return 0;
    else{
        while(raiz->dir != NULL)
            raiz = raiz->dir;
        return raiz->valor;
    }
}


int main(void){
    Node *raiz = NULL;
    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);
    inserir(&raiz, 61);
    inserir(&raiz, 98);
    
    printf("%d ", maior(raiz));
    return 0;
}