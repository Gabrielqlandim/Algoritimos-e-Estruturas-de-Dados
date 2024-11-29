#include <stdio.h>
#include <stdlib.h>
//busca do no pai 30/10
typedef struct Node{
    int valor;
    struct Node*dir;
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

Node* buscaPai(Node *raiz, int chave){
    if(raiz == NULL)
        return 0;
    else{
        if((raiz->esq != NULL && raiz->esq->valor == chave) || (raiz->dir != NULL && raiz->dir->valor == chave))
            return raiz;
        
        if(chave<raiz->valor)
            return buscaPai(raiz->esq, chave);
        else
            return buscaPai(raiz->dir, chave);
    }
}

int main(void){
    Node *raiz = NULL;
    inserir(&raiz, 23);
    inserir(&raiz, 15);
    inserir(&raiz, 42);
    inserir(&raiz, 7);
    inserir(&raiz, 31);
    
    Node *pai = buscaPai(raiz, 7);
    
    if(pai != NULL)
        printf("%d ", pai->valor);
    else 
        printf("Tem pai nao");
    return 0;
}