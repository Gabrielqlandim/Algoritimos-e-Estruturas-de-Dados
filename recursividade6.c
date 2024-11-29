#include <stdio.h>



void dec(int n){
    if(n==0){
        printf("%d", n);
    }
    else{
        printf("%d ", n);
        dec(n-1);
    }
}
int main(void){
    int n;
    printf("Digite o valor: ");
    scanf("%d", &n);
    dec(n);
    return 0;

}