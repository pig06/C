#include <stdio.h>
#include <stdlib.h> 

#define SIZE 100000
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int abs(int num) // num의 절댓값을 반환하는 함수 (절댓값: Absolute Value)
{
    return num > 0 ? num : num*-1;
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

int main()
{
    int N , i;
    int ph[SIZE];
    int front, end;
    int temp, opt_ph;
    int frontResult;
    int endResult;

    scanf("%d" , &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d" , &ph[i]);
    }
    
    quick_sort_random(ph , 0 , N - 1);
    
    front = 0; 
    end = N-1;

    opt_ph = ph[0] + ph[N - 1];
    while(front < end)
    {
        temp = ph[front] + ph[end];

        if(abs(opt_ph) >= abs(temp))
        {
            opt_ph = temp;
            frontResult = ph[front];
            endResult =ph[end];
            if(temp == 0) break;
        }

        if(temp > 0) end--;
        else front++;

    }  


    printf("%d %d", frontResult , endResult);

    return 0;
}