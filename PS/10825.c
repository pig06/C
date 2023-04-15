#include <stdio.h>
#include <stdlib.h> // qsort() Function
#include <string.h> // strcpy(), strcmp() Function

#define MAX 100000
#define NAME 11

typedef struct student
{
    int korean;
    int english;
    int math;
    char name[NAME];
} student;

// const: constant (상수; 항상 변하지 않는 수) <-> variable (변수; 변하는 수)
int compar(const void *value1, const void *value2)
{
    // 1순위: 국어 점수 내림차순
    // 2순위: 영어 점수 오름차순
    // 3순위: 수학 점수 내림차순
    // 4순위: 이름

    const student *a = (student *)value1;
    const student *b = (student *)value2;

    if (a->korean > b->korean)
    {
        return -1; // a가 b보다 앞에오는 경우
    }
    else if (a->korean < b->korean)
    {
        return +1; // a가 b보다 뒤에오는 경우
    }
    else // a->korean == b->korean
    {
        if (a->english < b->english)
        {
            return -1; // a가 b보다 앞에오는 경우
        }
        else if (a->english > b->english)
        {
            return +1; // a가 b보다 뒤에오는 경우
        }
        else // a->english == b->english
        {
            if (a->math > b->math)
            {
                return -1; // a가 b보다 앞에오는 경우
            }
            else if (a->math < b->math)
            {
                return +1; // a가 b보다 뒤에오는 경우
            }
            else // a->math == b->math
            {
                if (strcmp(a->name, b->name) == 0)
                    return 0;
                else if (strcmp(a->name, b->name) < 0)
                    return -1; // a가 b보다 앞에오는 경우
                else
                    return +1; // a가 b보다 뒤에오는 경우
            }
        }
    }
}

int main()
{
    int N; // 학생 수
    student result[MAX];
    int i;

    // 입력 처리
    scanf("%d", &N);
    char a[NAME];
    int b, c, d;
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", &a, &b, &c, &d);

        strcpy(result[i].name, a); // result[i].name = a;
        result[i].korean = b;
        result[i].english = c;
        result[i].math = d;
    }

    // 정렬
    qsort(result, N, sizeof(student), compar);

    // 정답 출력
    for (i = 0; i < N; i++)
        printf("%s\n", result[i].name);

    // 프로그램 종료
    return 0;
}
