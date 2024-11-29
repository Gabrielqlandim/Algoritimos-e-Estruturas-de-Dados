#include <stdio.h>
#include <stdlib.h>
void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int inicio, int fim){
    int pivo = v[fim], indice = inicio;

    for(int i=inicio; i<fim; i++){
        if(v[i]<= pivo){
            troca(v, i, indice);
            indice++;
        }
    }

    troca(v, fim, indice);
    return indice;
}

void quicksort(int v[], int inicio, int fim){
    if(inicio<fim){
        int indice = particao(v, inicio, fim);
        quicksort(v, inicio, indice-1);
        quicksort(v, indice+1, fim);

    }
}

int main(void){
    system("CLS");
    int v[] = {93,17,45,23,84,75,12,33};
    int tamanho = sizeof(v)/sizeof(v[0]);
    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
    
    quicksort(v, 0, tamanho-1);

    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}