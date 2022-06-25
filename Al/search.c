#include <stdio.h>

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