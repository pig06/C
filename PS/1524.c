#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int cmp(const void* a, const void* b){
    if( (int)a < (int)b)
        return -1;
    else if ( (int)a > (int)b)
        return +1;
    else
        return 0;
}

int main(){

    int T; // Test Cases
    scanf("%d", &T);

    while(T--) {

        // 1. Input processing
        int N, M;
        scanf("%d %d", &N, &M);

        int force_n[SIZE];
        for(int i=0; i<N; i++)
            scanf("%d", &force_n[i]);

        int force_m[SIZE];
        for(int i=0; i<M; i++)
            scanf("%d", &force_m[i]);


        // 2. Sorting
        qsort(force_n, N, sizeof(int), cmp);
        qsort(force_m, M, sizeof(int), cmp);


        // 3. Comparison & Choice
        int idx_n=0;
        int idx_m=0;

        for(int i=0; i<N+M; i++){
            if(force_n[idx_n] < force_m[idx_m])
                idx_n++;
            else //(force_n[idx_n] >= force_m[idx_m])
                idx_m++;


            // 4. Answering
            if(idx_n == N){
                printf("B\n");
                break;
            }
            else if(idx_m == M){
                printf("S\n");
                break;
            }
        }
    }
}