#include <stdio.h>

int main(){
    int N = 0,K = 0,i,num = 0;
    scanf("%d %d" , &N , &K);
    

    for (i = 1; i <= N;i++){
        if (N%i==0){
            num++;
        }
        if (num == K){
            printf("%d" , i);
            return 0;
        }

    }

    printf("0");
    return 0;
    
}