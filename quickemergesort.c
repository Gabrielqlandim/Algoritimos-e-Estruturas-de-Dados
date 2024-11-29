#include <stdio.h>

void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int particao(int v[], int inicio, int fim){
    int pivo = v[inicio], indice = fim;

    for(int i=fim; i>inicio;i--){
        if(v[i]>= pivo){
            troca(v,i,indice);
            indice--;
        }
    }
    troca(v,inicio,indice);
    return indice;
}

void quicksort(int v[], int inicio, int fim){
    if(inicio<fim){
        int indice = particao(v,inicio, fim);
        quicksort(v, inicio,indice-1);
        quicksort(v,indice+1,fim);
    }
}

void intercala(int v[], int inicio, int meio, int fim, int tam){
    int inicio_V1 = inicio;
    int inicio_V2 = meio +1;
    int poslivre = 0;
    int aux[tam];
    while(inicio_V1<=meio && inicio_V2<=fim){
        if(v[inicio_V1]<=v[inicio_V2])
            aux[poslivre++] = v[inicio_V1++];
        else
            aux[poslivre++] = v[inicio_V2++];
    }

    while(inicio_V1<=meio)
        aux[poslivre++] = v[inicio_V1++];
    while(inicio_V2<=fim)
        aux[poslivre++] = v[inicio_V2++];
    for(inicio_V1 = inicio; inicio_V1<=fim; inicio_V1++)
        v[inicio_V1] = aux[inicio_V1-inicio];
}

void mergesort(int v[], int inicio, int fim, int tam){
    if(inicio<fim){
        int meio = (inicio + fim)/2;

        mergesort(v,inicio, meio, tam);
        mergesort(v, meio+1, fim, tam);
        intercala(v,inicio, meio, fim, tam);
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

    int o;
    printf("digite 1 para merge e 2 para quick: ");
    scanf("%d", &o);

    printf("\n");

    if(o==1)
        mergesort(v, 0, tamanho-1, tamanho);
    if(o==2)
        quicksort(v, 0, tamanho-1);
    
    printf("\n");
    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}