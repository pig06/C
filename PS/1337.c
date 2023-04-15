#include <stdio.h>
#include <stdlib.h>

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
    int N;
    int arr[50];
    int i, front=0, back=0;
    int curr_cnt=0; // 삽입해야할 원소의 개수
    int min_cnt=5; // 삽입해야할 원소의 최소 개수 (정답)

    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &arr[i]);

    // 배열 정렬
    quick_sort_random(arr, 0, N-1);

    // 투 포인터
    while(front <= back && back < N)
    {
        if(arr[back] - arr[front] > 4)
            front++;
        else // 마지막 원소와 첫 원소의 차이가 4 이하인
        {
            curr_cnt = 5 - (back - front + 1);
            min_cnt = curr_cnt < min_cnt ? curr_cnt : min_cnt;
            back++;
        }
    }

    // 정답 출력
    printf("%d\n", min_cnt);

    return 0;
}