
/*
    BOJ 10610

    - 최대 100,000 자릿수의 숫자가 입력됨
    - 가장 큰 30의 배수를 만들어내야 됨

    * 30의 배수의 특징
    - 각 자릿수의 합이 3의 배수 (3의 배수의 특징)
    - 0이 하나 이상 포함되어 있어야 함 (10의 배수의 특징)
*/

#define IMPLEMENT // 우리가 구현한 quick_sort 로직을 사용

#include <stdio.h>
#include <string.h> // strlen() Function
#include <stdlib.h>

#define SIZE 100000 + 1
#define TRUE 1
#define FALSE 0

// Functions
void swap(char *a, char *b);
int partition_random(char A[], int p, int r);
void quick_sort_random(char A[], int p, int r);

int is_multiple_3(char N[], int len);
int is_multiple_10(char N[], int len);
int is_multiple_30(char N[], int len);

int comp(const void *a, const void *b)
{
    const char *x = (const char *)a;
    const char *y = (const char *)b;

    if (*x > *y)
        return -1;
    else if (*x == *y)
        return 0;
    else
        return 1;
}

int main()
{
    char N[SIZE];
    int len;

    memset(N, '\0', sizeof(char) * SIZE); // 문자열 배열은 사용하기 전 초기화 필수!! (오류의 원인)
    scanf("%s", N);

    // N의 각 자릿수의 합이 3의 배수인가? (3의 배수의 특징)
    // N에 0이 하나 이상 포함되어 있는가? (10의 배수의 특징)
    len = strlen(N);
    if (!is_multiple_30(N, len))
    {
        printf("-1\n");
        return 0;
    }

    // "가장 큰" 30의 배수를 출력 -> 정렬로 해결
#ifdef IMPLEMENT
    quick_sort_random(N, 0, strlen(N) - 1);
#endif

#ifndef IMPLEMENT
    qsort(N, sizeof(N) - 1, sizeof(char), comp);
#endif

    printf("%s\n", N);

    // 프로그램 종료
    return 0;
}

int is_multiple_30(char N[], int len)
{
    int i, sum = 0, exist_0 = FALSE;

    for (i = 0; i < len; i++)
    {
        if (N[i] == '0')
            exist_0 = TRUE;

        sum += N[i] - '0';
    }

    if (sum % 3 == 0 && exist_0)
        return TRUE;

    return FALSE;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition_random(char A[], int p, int r)
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
        if (A[j] >= A[r])
            swap(&A[++i], &A[j]);
    }

    swap(&A[i + 1], &A[r]);
    return i + 1; // 기준원소의 인덱스
}

void quick_sort_random(char A[], int p, int r)
{
    // A: 정렬할 배열
    // p: 정렬할 배열의 첫 번째 인덱스
    // r: 정렬할 배열의 마지막 인덱스 (배열의 크기 - 1)

    int q; // 기준 원소의 인덱스
    if (p < r)
    {
        q = partition_random(A, p, r);
        quick_sort_random(A, p, q - 1); // 왼쪽 서브배열에 대한 Quick Sort
        quick_sort_random(A, q + 1, r); // 오른쪽 서브배열에 대한 Quick Sort
    }
}