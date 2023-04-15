// BOJ 17224: APC는 왜 서브태스크 대회가 되었을까?

#include <stdio.h>
#include <stdlib.h> // Standard Library의 약자, for qsort() Function

/*
    qsort() 함수
    프로토타입: void qsort(
                    void *base,   // 정렬할 배열
                    size_t nel,   // 정렬할 배열의 원소의 개수
                    size_t width, // 정렬할 배열의 크기(Byte 단위)
                    int (*compar)(const void *, const void *)) // 정렬의 기준이 되는 함수
    ;
*/

#define MAX 100
// #define DEBUG_MODE

// 구조체 정의
typedef struct level
{
    int easy; // 쉬운 버전의 난이도
    int hard; // 어려운 버전의 난이도
} level;      // Aliasing (이름 바꾸기)

// 정렬할 기준이 되는 함수
int compare(const void *a, const void *b)
// 0보다 작은 값을 리턴: a가 b보다 앞서는 경우
// 0을 리턴: a와 b가 정확히 같은 경우
// 0보다 큰 값을 리턴: a가 b보다 뒤에 있는 경우
{
    // a와 b가 정확히 같은 경우
    if (((level *)a)->easy == ((level *)b)->easy && ((level *)a)->hard == ((level *)b)->hard)
        return 0;
    else
    {
        if (((level *)a)->hard < ((level *)b)->hard)
            return -1;

        else if (((level *)a)->hard > ((level *)b)->hard)
            return +1;

        else // hard 모드의 난이도가 같은 경우
        {
            if (((level *)a)->easy < ((level *)b)->easy)
                return -1;
            else
                return +1;
        }
    }
}

int main()
{
    int N; // 문제의 개수
    int L; // 참가자의 역량 (풀 수 있는 난이도의 최댓값)
    int K; // 풀 수 있는 문제의 최대 개수

    level levels[MAX]; // 구조체 배열 선언
    int score = 0;     // 취득 점수
    int solved = 0;    // 현재까지 풀이한 문제 개수

    int i;

    scanf("%d %d %d", &N, &L, &K);

    for (i = 0; i < N; i++)
        scanf("%d %d", &levels[i].easy, &levels[i].hard);

#ifdef DEBUG_MODE
    printf("BEFORE SORTING\n");
    for (i = 0; i < N; i++)
        printf("EASY: %d \t HARD: %d\n", levels[i].easy, levels[i].hard);
#endif

    // 구조체 배열 정렬
    qsort(levels, N, sizeof(level), compare);

#ifdef DEBUG_MODE
    printf("\nAFTER SORTING\n");
    for (i = 0; i < N; i++)
        printf("EASY: %d \t HARD: %d\n", levels[i].easy, levels[i].hard);
#endif

    // 점수 계산
    for (i = 0; i < N && solved < K; i++)
    {
        if (L >= levels[i].hard)
        {
            score += 140;
            solved++;
        }
        else if (L >= levels[i].easy)
        {
            score += 100;
            solved++;
        }
    }

    // 정답 출력
    printf("%d\n", score);

    // 프로그램 종료
    return 0;
}