#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, result = 0;
    scanf("%d" , &N);
    while(1){
        if(N%5==0){
            result += N/5;
            printf("%d" , result);
            exit(EXIT_SUCCESS);
        }
        N-=3;
        result++;
        if(N<0){
            printf("-1");
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_FAILURE);
}