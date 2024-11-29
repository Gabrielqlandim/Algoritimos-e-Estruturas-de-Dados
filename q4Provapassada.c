#include<stdio.h>

void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int inicio, int fim){
    int pivo = v[inicio], indice = fim;

    for(int i=fim; i>inicio; i--){
        if(v[i]>=pivo){
            troca(v,i,indice);
            indice--;
        }
    }
    troca(v,inicio, indice);
    return indice;
}

void quicksort(int v[], int inicio, int fim){
    if(inicio<fim){
        int indice = particao(v, inicio, fim);
        quicksort(v,inicio, indice-1);
        quicksort(v,indice+1, fim);
    }
}

int main(void){
    int v[] = {8,6,4,1};
    int tam = sizeof(v)/sizeof(v[0]);

    quicksort(v,0,tam-1);

    for(int i=0;i<tam;i++)
        printf("%d ", v[i]);
    return 0;
}

//no melhor caso o quicksort ele tem uma complexidade de O(n log N), ja no pior ele tem uma complexidade de O(N^2)