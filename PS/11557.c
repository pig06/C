#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drunk
{
    char S[21]; // 학교 이름
    int L;      // 소비한 술의 양
} drunk;

int compar(const void * a, const void * b)
{
    drunk first = *((drunk *)a);
    drunk second = *((drunk *)b);

    if (first.L < second.L)
        return +1;
    else if (first.L > second.L)
        return -1;
    else
    {
        return strcmp(first.S, second.S);
    }
    // first와 second 사이의 우선순위를 가려내는 로직
    
}

int main()
{
    int T;                  // 테스트 케이스의 수
    int N;                  // 학교의 수
    drunk school_list[100]; // 학교가 소비한 술의 양 정보를 담은 구조체 배열
    int i;

    scanf("%d", &T);

    while (T--)
    {
        // 입력 처리
        scanf("%d", &N);

        for (i = 0; i < N; i++)
            scanf("%s %d", school_list[i].S, &school_list[i].L);

        // 정렬 (내림차순)
        qsort(school_list, N, sizeof(drunk), compar);

        // 정답 출력
        printf("%s\n", school_list[0].S);
    }

    // 프로그램 종료
    return 0;
}