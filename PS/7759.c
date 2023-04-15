#include <stdio.h>
#include <stdlib.h> // rand(), srand() Functions

#define SIZE 20000

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

    int rand_idx = (rand() % (r - p + 1)) + p;
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
    int T;
    int A[SIZE], N;
    int B[SIZE], M;
    int cnt;
    int i, j;

    scanf("%d", &T);

    while (T--)
    {
        // 1. 입력
        scanf("%d %d", &N, &M);

        for (i = 0; i < N; i++)
            scanf("%d", &A[i]);

        for (i = 0; i < M; i++)
            scanf("%d", &B[i]);

        cnt = 0;

        // 2. 정렬
        quick_sort_random(B, 0, M - 1);

        // 3. 대소 비교
        for (i = 0; i < N; i++) // 집합 A의 모든 원소에 대한 탐색
        {
            for (j = 0; j < M; j++) //집합 B에 대해서는, A 이상인 경우는 무시
            {
                if (A[i] > B[j])
                    cnt++;
                else // A[i] <= B[j]
                    break;
            }
        }

        // 4. 결과 출력
        printf("%d\n", cnt);
    }

    return 0;
}