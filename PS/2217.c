#include <stdio.h>
#include <stdlib.h>   // rand(), srand() Functions

#define SIZE 30000
#define MAX 100000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_random(int A[], int p, int r)
{
    // 기준 원소를 랜덤하게 선정하고 인덱스 값을 리턴하고,
    // 작은 원소는 왼쪽 서브배열로,
    // 큰 원소는 오른쪽 서브배열로 옮기는 작업을 하는 함수

    int rand_idx = (rand()%(r-p+1))+p;
    swap(&A[r], &A[rand_idx]);

    int i = p - 1;
    int j;

    for (j = p; j < r; j++)
    {
        if (A[j] <= A[r])
            swap(&A[++i], &A[j]);
    }

    swap(&A[i + 1], &A[r]);
    return i + 1; // 기준원소의 인덱스
}

void quick_sort_random(int A[], int p, int r)


{
    // A: 정렬할 배열
    // p: 정렬할 배열의 첫 번째 인덱스
    // r: 정렬할 배열의 마지막 인덱스

    int q; // 기준 원소의 인덱스
    if (p < r)
    {
        q = partition_random(A, p, r);
        quick_sort_random(A, p, q - 1); // 왼쪽 서브배열에 대한 Quick Sort
        quick_sort_random(A, q + 1, r); // 오른쪽 서브배열에 대한 Quick Sort
    }
}


int calc_max_weight(int A[], int n, int k)
{
   return  A[n - k] * k;
}
int main(){
    int N;
    int i , max = 0;
    int ropes[MAX];
    scanf ("%d" , &N);
    for (i = 0;i < N;i++){
        scanf("%d", &ropes[i]);

    }
    quick_sort_random(ropes , 0 , N -1);

    for(i = N; i>= 1; i--){
        if(calc_max_weight(ropes,N, i) > max){
            max = calc_max_weight(ropes ,N, i);
        }
    }
    printf("%d\n" , max);
    return 0;
}