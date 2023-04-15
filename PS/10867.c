// BOJ 10867: 중복 빼고 정렬하기

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int compar(const void* a, const void* b)
{
    const int first = *((int *)a);
    const int second = *((int *)b);
    if(first < second)
        return -1;
    else if(first > second)
        return +1;
    else return 0;
}

int main()
{
    int N;
    int arr[MAX];
    int i;

    // 입력 처리
    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    // 정렬
    qsort(arr, N, sizeof(int), compar);

    // 정답 출력 (중복 제거)
    
    // 프로그램 종료
    for(i = 0; i < N;i++)
    {
        if (arr[i-1] != arr[i])
        {
            printf("%d " , arr[i]);
        }
       
    }
   
    return 0;
}