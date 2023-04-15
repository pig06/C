#include <stdio.h>
#include <time.h>    // clock() Function
#include <stdlib.h>   // rand(), srand() Functions

#define SIZE 1000000 // 1M

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

int main()
{
    int arr[SIZE];
    int n, x, i;
    int start, end, cnt_pairs=0;

    // 입력 처리
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    scanf("%d", &x);

    // 정렬
    quick_sort_random(arr, 0, n-1);

    // 투 포인터 알고리즘
    start = 0; end = n-1;
    while(start < end)
    {
        if(arr[start] + arr[end] < x)
            start++;
        else if(arr[start] + arr[end] > x)
            end--;
        else // (arr[start] + arr[end] == x)
        {
            cnt_pairs++; // x값을 만드는 쌍 발견!
            start++;
            end--;
        }
    }

    // 결과 출력
    printf("%d\n", cnt_pairs);

    // 종료
    return 0;
}