#include <stdio.h>
#include <algorithm>
#define MAX 10


int main(){
    int T;
    scanf("%d", &T);
    while (T--){

        int N,K;
        int i;
        int A[MAX];

        N = 10;
        K = 3;

        for (i = 0; i < N; i++){
            scanf("%d" , &A[i]);
        }

        std::sort(A, A+N);

        printf("%d\n" , A[N - K]);

    }

}