#include <stdio.h>
#include <algorithm> // sort() Function
#include <cstdlib>

#define SIZE 1000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int A[], int n)
// A[] : 정렬할 배열
// n   : A의 크기
{
    int i, j;
    int curr_max; // 현재 발견된 최댓값의 인덱스

    for (i = n - 1; i > 0; i--) // A[1 ... n-1]
    {
        // curr_max = A[i]부터 A[0] 중에서 가장 큰 값
        curr_max = 0;
        for (j = 0; j <= i; j++)
        {
            if (A[curr_max] < A[j])
                curr_max = j;
        }

        swap(&A[curr_max], &A[i]);
    }
}

void bubble_sort(int A[], int n)
{
    int i, last;
    for (last = n - 1; last > 1; last--)
    {
        for (i = 0; i <= last - 1; i++)
        {
            if (A[i] > A[i + 1])
                swap(&A[i], &A[i + 1]);
        }
    }
}

void insertion_sort(int A[], int n)
{
    int loc, newItem;
    int i;

    for (i = 1; i < n; i++)
    {
        loc = i - 1;
        newItem = A[i];
        while ((loc >= 0) && (newItem < A[loc]))
        {
            A[loc + 1] = A[loc];
            loc--;
        }
        A[loc + 1] = newItem;
    }
}

void merge(int A[], int p, int q, int r)
{
    // A: 정렬할 배열
    // p: 정렬할 배열의 첫 번째 인덱스
    // q: p와 r의 중간지점
    // r: 정렬할 배열의 마지막 인덱스
    int i = p;
    int j = q + 1;
    int t = 0;
    int tmp[SIZE];

    while (i <= q && j <= r) // 두 서브배열을 비교하며 순차적으로 병합
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= q) // 왼쪽 서브배열이 남은 경우
        tmp[t++] = A[i++];

    while (j <= r) // 오른쪽 서브배열이 남은 경우
        tmp[t++] = A[j++];

    i = p;
    t = 0;

    while (i <= r) // 임시배열(tmp)을 원본배열(A)로 복사
        A[i++] = tmp[t++];
}

void merge_sort(int A[], int p, int r)
{
    // A: 정렬할 배열
    // p: 정렬할 배열의 첫 번째 인덱스
    // r: 정렬할 배열의 마지막 인덱스
    if (p < r)
    {
        int q = (p + r) / 2;     // p와 r의 중간 지점
        merge_sort(A, p, q);     // A의 전반부를 Split
        merge_sort(A, q + 1, r); // A의 후반부를 Split
        merge(A, p, q, r);       // 전반부와 후반부를 Merge
    }
}

int partition(int A[], int p, int r)
{
    // 기준 원소를 선정하고 인덱스 값을 리턴하고,
    // 작은 원소는 왼쪽 서브배열로,
    // 큰 원소는 오른쪽 서브배열로 옮기는 작업을 하는 함수

    int x = A[r];
    int i = p - 1;
    int j;

    for (j = p; j < r; j++)
    {
        if (A[j] <= x)
            swap(&A[++i], &A[j]);
    }

    swap(&A[i + 1], &A[r]);
    return i + 1; // 기준원소의 인덱스
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


void quick_sort(int A[], int p, int r)
{
    // A: 정렬할 배열
    // p: 정렬할 배열의 첫 번째 인덱스
    // r: 정렬할 배열의 마지막 인덱스

    int q; // 기준 원소의 인덱스
    if (p < r)
    {
        q = partition(A, p, r);
        quick_sort(A, p, q - 1); // 왼쪽 서브배열에 대한 Quick Sort
        quick_sort(A, q + 1, r); // 오른쪽 서브배열에 대한 Quick Sort
    }
}

void print(int A[], int n)
{
    
}

int main()
{
    int N,i, sum = 0;
    int A[50];
    int B[50];
    scanf("%d" , &N);

    for(i = 0;i < N; i++){
        scanf("%d" , &A[i]);
    }
    for(i = 0;i < N; i++){
        scanf("%d" , &B[i]);
    }

    quick_sort(A, 0 , N - 1);
    quick_sort(B, 0 , N - 1);
    
    for (i = 0; i < N; i++){
        sum +=  A[i] * B[N - 1 - i];
    }

    printf("%d\n" , sum);
    
    
   // print(, 10);

    // selection_sort(A, n);
    // bubble_sort(A, n);
    // insertion_sort(A, n);
  
    return 0;
}