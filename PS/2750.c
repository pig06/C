#include <stdio.h>
#define MAX 1000
void swap(int *a, int  *b);
void insertion_sort(int A[], int n);
void print(int A[], int n);

int main(){
    int A[MAX];
    int n;
    scanf("%d" , &n);
     for (int i = 0; i< n; i++){
        scanf("%d" , &A[i]);

    }
    insertion_sort(A,n);
    print(A,n);

    return 0;
}
void swap(int *a, int  *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion_sort(int A[], int n){
    int i , j;
    int curr_max;

    for (i = n-1;i > 0; i--){

        curr_max = 0;
        for (j = 0; j <= i; j++){
            if (A[curr_max] < A[j]) {
                curr_max = j;
            }
        }

        swap(&A[curr_max],&A[i]);
    }
}
void print(int A[], int n)
{
    int i;
    for(i = 0; i< n;i++){
        printf("%d\n" , A[i]);

    }printf("\n");
}