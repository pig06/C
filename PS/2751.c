#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int comp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int N[MAX];
    int len;
    scanf("%d" , &len);
    for (int i =0; i< len; i++){
        scanf("%d" , &N[i]);
    }
    qsort(N, len, sizeof(int), comp);
    for (int i =0; i< len; i++){
        printf("%d\n" , N[i]);
    }
    exit(EXIT_SUCCESS);
}