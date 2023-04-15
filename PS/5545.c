// BOJ 5545: 최고의 피자
// 가격 당 최대 열량 = (열량) / (가격)

#include <stdio.h>
#include <stdlib.h> // qsort() Function

#define MAX 10000

int compare(const void* a, const void* b)
{
    if(*((int *)a) > *((int *)b))
        return -1;
    else if(*((int *)a) == *((int *)b))
        return 0;
    else
        return +1;
}

int main()
{
    int N;      // 토핑의 종류의 수
    int A;      // 도우의 가격
    int B;      // 토핑의 가격
    int C;      // 도우의 열량
    int D[MAX]; // 각 토핑들의 열량

    int i;
    int curr_ratio;  // 가격 당 칼로리 (정답)
    int total_cal;   // 총 칼로리
    int total_price; // 총 가격
    int temp;

    // 입력 처리
    scanf("%d", &N);        // 토핑 종류의 수 입력
    scanf("%d %d", &A, &B); // 도우의 가격, 토핑의 가격 입력
    scanf("%d", &C);        // 도우의 열량 입력
    for (i = 0; i < N; i++) // 각 토핑의 열량 입력
        scanf("%d", &D[i]);

    // 정렬
    qsort(D, N, sizeof(int), compare);

    // 계산
    total_cal = C;
    total_price = A;
    curr_ratio = total_cal / total_price;

    for(i = 0; i < N; i++)
    {
        total_cal += D[i]; // 분자
        total_price += B;  // 분모

        temp = total_cal / total_price;

        if(curr_ratio < temp)
            curr_ratio = temp;
    }

    // 정답 출력
    printf("%d\n", curr_ratio);

    // 프로그램 종료
    return 0;
}
