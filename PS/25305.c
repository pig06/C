#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int compar(const void* value1, const void* value2)
{
    // 내림차순 정렬

    const int* a = (int *)value1;
    const int* b = (int *)value2;

    if(*a > *b)
        return -1;
    else if(*a < *b)
        return +1;
    else
        return 0;
}

int main()
{
    int N; // 학생 수
    int k; // 수상자 중 최하위 순위
    int scores[SIZE]; // 점수
    int i;

    // 입력 처리
    scanf("%d %d", &N, &k);
    for(i=0; i<N;i++)
        scanf("%d", &scores[i]);

    // 정렬
    qsort(scores, N, sizeof(int), compar);

    // 정답 출력
    printf("%d\n", scores[k-1]);

    // 프로그램 종료
    return 0;
}