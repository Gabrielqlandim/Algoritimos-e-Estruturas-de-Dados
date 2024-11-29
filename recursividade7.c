#include<stdio.h>

int pot(int x, int n){
    if(n==0){
        return 1;
    }
    else{
        return x* pot(x,n-1);
    }
}

int main(void){
    int n,x;

    printf("Digite dois valores: ");
    scanf("%d %d",&x, &n);

    int r = pot(x,n);
    printf("Resultado: %d", r );
}