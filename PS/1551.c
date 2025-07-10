#include <stdio.h>
#include <stdlib.h>

#define MAX 21

int main(){
    int N,K;
    int A[MAX];

    scanf("%d %d", &N , &K);

    for (int i = 0; i < N; i++){
        scanf("%d,", &A[i]);
    }

    for(int i = 0; i < K; i++){
        for (int j = 0; j < N-1;j++){
            A[j]=A[j+1] - A[j];
        }
        N--;
    }

    for (int i = 0; i < N-1; i++){
        printf("%d," ,A[i]);
    }
    printf("%d" , A[N-1]);

    exit(EXIT_SUCCESS);
}