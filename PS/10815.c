#include <stdio.h>

#define MAX 500000

void swap(int *a, int *b);
int partition(int A[], int p, int r);
void quick_sort(int A[], int p, int r);

// 순차 탐색 (Sequential Search)
// 배열 arr 내부에 key가 있는지를 탐색
// key가 있으면 "1"을 출력
// key가 없으면 "0"을 출력
void sequential_search(int arr[], int size, int key);

// 이진 탐색 (Binary Search)
// 배열 arr 내부에 key가 있는지를 탐색
// 단, 배열 arr은 정렬된 배열
// key가 있으면 "1"을 출력
// key가 없으면 "0"을 출력
void binary_search(int arr[], int size, int key);

int main()
{
    int cards[MAX];
    int N, M;
    int i, input;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &cards[i]);

    // 카드 정렬
    quick_sort(cards, 0, N - 1);

    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &input);
        binary_search(cards, N, input);
    }

    printf("\n");

    return 0;
}

void sequential_search(int arr[], int size, int key)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("1 ");
            return;
        }
    }

    printf("0 ");
    return;
}

void binary_search(int arr[], int size, int key)
{
    int start = 0;      // 배열의 시작 인덱스
    int mid;            // 배열의 중간 인덱스
    int end = size - 1; // 배열의 마지막 인덱스

    while( start <= end )
    {
        mid = (start + end) / 2;

        if(arr[mid] == key)
        {
            printf("1 ");
            return;
        }
        else if(arr[mid] < key)
            start = mid + 1;
        else // arr[mid] > key
            end = mid - 1;
    }

    printf("0 ");
    return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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