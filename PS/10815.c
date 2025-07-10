#include <stdio.h>
#include <stdlib.h>

#define SIZE 500000

int comp(const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return -1;
    else if(*(int*)a == *(int*)b)
        return 0;
    else
        return +1;
}

int main(){
    int N,M;
    int arr_N[SIZE];
    int arr_M[SIZE];

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d" , &arr_N[i]);
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d" , &arr_M[i]);
    }

    qsort(arr_N,N, sizeof(arr_N[0]), comp);

    for(int i=0; i < M;i++){
        int key = arr_M[i];
        int *res = bsearch(&key, arr_N, N,sizeof(arr_N[0]), comp);

        if(res == NULL)
            printf("0 ");
        else
            printf("1 ");
    }

    exit(EXIT_SUCCESS);
}
