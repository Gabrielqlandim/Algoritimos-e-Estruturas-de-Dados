#include <stdio.h>


int main(void){
    int n;

    printf("Tamahno do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for(int i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }

    for(int i=1; i<=n-1;i++){
        for(int j=n-1;j>=i;j--){
            if(vet[j]<vet[j-1]){
                int aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1]=aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ", vet[i]);
    }
    return 0;
}