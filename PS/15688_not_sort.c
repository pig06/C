// 원솟값의 범위 : -1,000,000 ~ +1,000,000 : 2,000,001개의 원소

#include <stdio.h>
#include <string.h>

#define SIZE 2000001

int main()
{
    int arr[SIZE];
    int N, i, j, input;

    memset(arr, 0, sizeof(int) * SIZE);

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &input);
        arr[input + 1000000]++;
    }

    for (i = 0; i < SIZE; i++)
    {
        if (arr[i] != 0)
        {
            while (arr[i] > 0)
            {
                printf("%d\n", i - 1000000);
                arr[i]--;
            }
        }
        else
            continue;
    }

    return 0;
}
