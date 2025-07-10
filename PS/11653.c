#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int PN(int M) //소수 판독
{
    if (M < 2)
    {
        return false;
    }
    for(int i = 2; i*i <= M; i++){
        if (M % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int N;
    scanf("%d" , &N);
    if(!PN(N)){
       for (int i= 2; i*i <= N; i++){
            while(N % i == 0){
                N = N / i;
                printf("%d\n", i);
            }
        }
    }
    if(N>1){
        printf("%d" , N);
    }
       
    exit(EXIT_SUCCESS);
}