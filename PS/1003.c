#include <stdio.h>

#define MAX 40

int main(){
    int fib[MAX+1][2];
    int T , i ,n;
    fib[0][0] = 1;
    fib[0][1] = 0;
    fib[1][0] = 0;
    fib[1][1] = 1;
    for (i = 2; i<=MAX;i++){
        fib[i][0] = fib[i-1][0] + fib[i-2][0];
        fib[i][1] = fib[i-1][1] + fib[i-2][1];
    }
    scanf("%d" , &T);
    while(T--){
        scanf("%d" , &n);
        printf("%d %d\n", fib[n][0],fib[n][1]);
    }

    return 0;

}