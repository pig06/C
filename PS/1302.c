// BOJ 1302: 베스트셀러

// #define DEBUG_MODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 // 책 종류의 최대 가짓수
#define STR 51   // 문자열의 최대 길이

typedef struct book
{
    char name[STR]; // 책 제목
    int sell;       // 판매량
} book;

int compar(const void* a, const void* b)
{
    const book first = *((book*)a);
    const book second = *((book*)b);

    if(first.sell > second.sell)
        return -1;
    else if(first.sell < second.sell)
        return +1;
    else // first.sell == second.sell
    {
        if(strcmp(first.name, second.name) < 0)
            return -1;
        else if(strcmp(first.name, second.name) > 0)
            return +1;
        else
            return 0;
    }
}

int main()
{
    int N;               // 입력의 개수
    book list[MAX];      // 책 정보 리스트
    int kinds = 0;       // 책 종류의 가짓수
    int i, j;            // 루프 변수
    char input_str[STR]; // 입력 문자열을 임시로 저장할 변수

    // 초기화
    for (i = 0; i < MAX; i++)
    {
        memset(list[i].name, '\0', sizeof(char) * STR);
        list[i].sell = 0;
    }

    // 입력 처리
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", input_str);

        if(kinds == 0)
        {
            strcpy(list[0].name, input_str);
            list[kinds].sell++;
            kinds++;
            continue;
        }

        for (j = 0; j < kinds; j++)
        {
            if (strcmp(list[j].name, input_str) == 0) // 두 문자열 비교
            {
                list[j].sell++;
                break;
            }
            else if (j == kinds - 1)
            {
                strcpy(list[kinds].name, input_str); // 문자열 복사
                list[kinds].sell++;
                kinds++;
                break;
            }
        }
    }

#ifdef DEBUG_MODE
    printf("Before Sort\n");
    for (i = 0; i < kinds; i++)
        printf("name: %15s \t sell: %d\n", list[i].name, list[i].sell);
    printf("\n");
#endif

    // 정렬
    qsort(list, kinds, sizeof(book), compar);

#ifdef DEBUG_MODE
    printf("After Sort\n");
    for (i = 0; i < kinds; i++)
        printf("name: %15s \t sell: %d\n", list[i].name, list[i].sell);
    printf("\n");
#endif

    // 정답 출력
    printf("%s\n", list[0].name);

    // 프로그램 종료
    return 0;
}