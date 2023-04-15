#include <stdio.h>
#include <string.h>

// Standard Library
#include <stdlib.h> // qsort() Function

#define MAX 100000

typedef struct
{
    int resume_rank;
    int interview_rank;
} Candidate_t; // Aliasing (이름 바꾸기, 이름 축약)

int cmpfunc(const void *a, const void *b)
{
    if(((Candidate_t *)a)->resume_rank < ((Candidate_t *)b)->resume_rank)
        return -1;
    else if(((Candidate_t *)a)->resume_rank > ((Candidate_t *)b)->resume_rank)
        return +1;
    else
    {
        if(((Candidate_t *)a)->interview_rank < ((Candidate_t *)b)->interview_rank)
            return -1;
        else if(((Candidate_t *)a)->interview_rank > ((Candidate_t *)b)->interview_rank)
            return +1;
        else
            return 0;
    }
}

int main(void)
{
    int T; // 테스트 케이스의 수
    int N; // 지원자(candidate)의 수
    int i;
    int max;
    int answer; // 선발할 수 있는 최대 신입사원의 수
    Candidate_t candidates[MAX];

    // 입력 처리
    scanf("%d", &T);

    while(T--)
    {
        // 초기화
        answer = 1;

        // 입력 처리
        scanf("%d", &N);
        for(i=0; i<N; i++)
            scanf("%d %d", &candidates[i].resume_rank, &candidates[i].interview_rank);
        
        // 계산
        qsort((Candidate_t *)candidates, N, sizeof(Candidate_t), cmpfunc);
        max = candidates[0].interview_rank;

        for(i=1; i<N; i++)
        {
            if(candidates[i].interview_rank > max)
                continue;
            else{
                answer++;
                max = candidates[i].interview_rank;
            }
        }

        // 출력
        printf("%d\n", answer);
    }

    return 0;
}