#include <stdio.h>

int num(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n)*2 + num(n-1);
    }
}

int main(void){
    System("CLS");
    int n;

    scanf("%d", &n);

    int r = num(n);
    printf("%d", r);
    return 0;
}