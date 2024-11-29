#include <stdio.h>

void intercala(int v[], int inicio, int meio, int fim, int tam){
    int inicio_V1 = inicio;
    int inicio_v2 = meio+1;
    int poslivre = 0;
    int aux[tam];

    while(inicio_V1<=meio && inicio_v2<=fim){
        if(v[inicio_V1] <= v[inicio_v2])
            aux[poslivre++] = v[inicio_V1++];
        else
            aux[poslivre++] = v[inicio_v2++];
    }

    while(inicio_V1 <= meio)
        aux[poslivre++] = v[inicio_V1++];
    
    while(inicio_v2 <= fim)
        aux[poslivre++] = v[inicio_v2++];
    
    for(inicio_V1 = inicio; inicio_V1<=fim; inicio_V1++)
        v[inicio_V1] = aux[inicio_V1-inicio];
}

void mergesort(int v[], int inicio, int fim, int tam){
    if(inicio<fim){
        int meio = (inicio + fim)/2;

        mergesort(v, inicio, meio, tam);
        mergesort(v, meio+1, fim, tam);
        intercala(v, inicio, meio, fim, tam);
    }
}

int main(void){
    system("cls");
    int v[] = {10, 3, 8, 12, 6};
    int tamanho = sizeof(v)/sizeof(v[0]);
    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    mergesort(v, 0, tamanho-1, tamanho);

    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;

}