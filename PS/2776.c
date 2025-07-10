#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define ARRAY_SIZE(arr)  (sizeof((arr)) / sizeof((arr)[0]))
#define SIZE 1000000

int comp(const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return -1;
    else if(*(int*)a == *(int*)b)
        return 0;
    else
        return +1;
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        int arr_n[SIZE];

        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d" , &arr_n[i]);
        }

        int m;
        int arr_m[SIZE];

        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d" , &arr_m[i]);
        }

        qsort(arr_n,n, sizeof(arr_n[0]), comp);

        for(int i=0; i < m;i++){
            int key = arr_m[i];
            int *res = bsearch(&key, arr_n, n,sizeof(arr_n[0]), comp);

            if(res == NULL)
                printf("0\n");
            else
                printf("1\n");
        }
    }

    exit(EXIT_SUCCESS);
}