#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *esq;
    struct Node *dir;
}Node;

void inserir(Node **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Node*)malloc(sizeof(Node));
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->valor = n;
    }
    else if(n<(*raiz)->valor)
        inserir(&(*raiz)->esq, n);
    else
        inserir(&(*raiz)->dir, n);
}

void inOrdem(Node *raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

Node *maiorDireita(Node **raiz){
    if((*raiz)->dir != NULL)
        return maiorDireita(&(*raiz)->dir);
    else{
        Node *aux = *raiz;
        if((*raiz)->esq != NULL)
            (*raiz) = (*raiz)->esq;
        else
            *raiz = NULL;
        return aux;
    }
}
int busca(Node *raiz, int n){
    if(raiz == NULL){
        return 0;
    }
    else if(n<raiz->valor)
        return busca(raiz->esq, n);
    else if(n>raiz->valor)
        return busca(raiz->dir, n);
    else 
        return 1;
    
}
void delete(Node **raiz, int n){
    if(*raiz == NULL)
        return;
        
    else if(n<(*raiz)->valor)
        delete(&(*raiz)->esq, n);
    else if(n>(*raiz)->valor)
        delete(&(*raiz)->dir, n);
    else{
        Node *aux = *raiz;
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            free(*raiz);
            *raiz = NULL;
        }
        else{
            if((*raiz)->esq == NULL){
                (*raiz) = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
            }
            else{
                if((*raiz)->dir == NULL){
                    (*raiz) = (*raiz)->esq;
                    aux->esq = NULL;
                    free(aux);
                }
                else{
                    aux = maiorDireita(&(*raiz)->esq);
                    aux->dir = (*raiz)->dir;
                    aux->esq = (*raiz)->esq;
                    (*raiz)->dir = (*raiz)->esq = NULL;
                    free(*raiz);
                    *raiz = aux;
                    aux = NULL;
                }
            }
        }
    }
}
int main(void){
    system("CLS");
    Node *raiz = NULL;
    inserir(&raiz, 10);
    inserir(&raiz, 15);
    inserir(&raiz, 5);

    printf("\n");
    printf("In ordem: ");
    inOrdem(raiz);

    printf("\n");
    delete(&raiz, 5);


    printf("\n");
    printf("In ordem: ");
    inOrdem(raiz);

    printf("Busca o 5: %d", busca(raiz, 5));
    return 0;
}