
/*
 * Structures (구조체)
 * - 비동질적 자료구조
 * - C언어에서 기본적으로 제공하고 있는 문법 (별다른 헤더파일 포함을 요구하지 않음)
 * - 키워드: struct
 */


#include <stdio.h>

// 기본적 구조체 선언 형태
struct score{
    char name;
    int resume_rank;
    int interview_rank;
};

// 단축형 구조체 선언 형태 (Aliasing; 엘리어싱)
typedef struct score_new{
    char name;
    int resume_rank;
    int interview_rank;
}score_new;

int main()
{
    score_new temp;
    struct score candidates[5];
    int i;

    temp.name = 'B';
    temp.resume_rank = 1;
    temp.interview_rank = 4;

    // Hard Coding (데이터 직접 입력)
    candidates[0].name = 'B';
    candidates[0].resume_rank = 1;
    candidates[0].interview_rank = 4;
    
    candidates[1].name = 'D';
    candidates[1].resume_rank = 2;
    candidates[1].interview_rank = 3;
    
    candidates[2].name = 'A';
    candidates[2].resume_rank = 3;
    candidates[2].interview_rank = 2;

    candidates[3].name = 'C';
    candidates[3].resume_rank = 4;
    candidates[3].interview_rank = 1;

    candidates[4].name = 'E';
    candidates[4].resume_rank = 5;
    candidates[4].interview_rank = 5;

    // 출력
    for(i=0; i<5; i++)
        printf("지원자 이름: %c    서류 순위: %d    면접 순위: %d\n", candidates[i].name, candidates[i].resume_rank, candidates[i].interview_rank);

    // 프로그램 종료
    return 0;
}