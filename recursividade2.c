#include <stdio.h>

int fib(int n){
    if(n==1){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    else{
        return fib(n-1) + fib(n-2);
    }

}

int main(void){
    int n;

    scanf("%d", &n);

    int r = fib(n);
    printf("%d", r);
    return 0;
}