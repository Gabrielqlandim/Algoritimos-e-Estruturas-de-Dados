#include <stdio.h>

int main(void){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];

    for(int i=0;i<n;i++){
        printf("Digite o numero para compor o vetor: ");
        scanf("%d", &vet[i]);
    }

    for(int i=1; i<=n;i++){
        for(int j=0;j<n-1;j++){
            if(vet[j]>vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }

    for(int i=1; i<=n;i++){
        for(int j=0;j<n-1;j++){
            if(vet[j]<vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}