#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // rand(), srand() Functions

#define SIZE 1000 + 1

void print(char str[SIZE][SIZE], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%s\n", str[i]);
}

void swap(char str1[SIZE], char str2[SIZE])
{
    char temp[SIZE];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int partition(char A[SIZE][SIZE], int p, int r)
{
    // 기준 원소를 랜덤하게 선정하고 인덱스 값을 리턴하고,
    // 작은 원소는 왼쪽 서브배열로,
    // 큰 원소는 오른쪽 서브배열로 옮기는 작업을 하는 함수

    int rand_idx = (rand()%(r-p+1))+p;
    swap(A[r], A[rand_idx]);

    int i = p - 1;
    int j;

    for (j = p; j < r; j++)
    {
        if (!(strcmp(A[j], A[r]) > 0)) // A[j]가 A[r] 과 같거나, 작다면
            swap(A[++i], A[j]);
    }

    swap(A[i + 1], A[r]);
    return i + 1; // 기준원소의 인덱스
}

void quick_sort(char A[SIZE][SIZE], int p, int r)
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

int main()
{
    char arr[SIZE][SIZE];
    int len; // 입력 문자열의 길이
    int i, j;

    memset(arr, '\0', sizeof(char) * SIZE * SIZE);

    scanf("%s", arr[0]);
    len = strlen(arr[0]);

    // 서브문자열 생성
    for (i = 1; i < len; i++)
    {
        for (j = i; j <= len; j++)
            arr[i][j - i] = arr[0][j];
    }

    // 문자열 정렬 (Bubble Sort)
    quick_sort(arr, 0, len-1);

    // 문자열 출력
    print(arr, len);

    return 0;
}