#include <stdio.h>

int main(){
    int N ,i, y;
    scanf("%d" , &N);

    if (N % 2 == 0)
    {
        for (i = 0; i< N; i++){
            for(y = 0; y < N;  y++){
                if (y == N / 2){
                    printf("\n ");
                }
                printf("* ");
            }
            printf("\n");
        }
    }
    else
    {
        for (i = 0; i< N; i++){
            for(y = 0; y < N;  y++){
                if (y == N / 2 + 1){
                    printf("\n ");
                }
                printf("* ");
            }
            printf("\n");
        }
    }
}