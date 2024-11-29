#include <stdio.h>

int main(void){
    int n;

    printf("Tamahno do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for(int i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }

    for(int i=1;i<n;i++){
        int j=i;

        while((vet[j]< vet[j-1]) && j>0){
            int aux = vet[j-1];
            vet[j-1] = vet[j];
            vet[j] = aux;
            --j;
        }
    }




    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}