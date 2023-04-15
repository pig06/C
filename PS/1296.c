
// #define DEBUG_MODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct info
{
    int score;
    char name[21];
} info;

int compar(const void *team1, const void *team2)
{
    const info* a = (info*)team1;
    const info* b = (info*)team2;

    if(a->score > b-> score)
        return -1;
    else if(a->score < b-> score)
        return +1;
    else // a->score == b-> score  ->  a와 b중 이름이 사전순으로 더 앞서는 팀을 우선시
        return strcmp(a->name, b->name);
}

int main()
{
    int N;           // 팀의 개수
    char yeondu[21]; // 연두의 이름
    int size_yeondu; // 연두 이름의 길이
    int size_team;   // 팀 이름의 길이

    info team_info[MAX];
    int L = 0, O = 0, V = 0, E = 0;                             // 'L', 'O', 'V', 'E'의 개수
    int yeondu_L = 0, yeondu_O = 0, yeondu_V = 0, yeondu_E = 0; // 연두의 이름에서 등장하는 'L', 'O', 'V', 'E'의 개수

    int i, j;

    // 초기화
    memset(yeondu, '\0', sizeof(char) * 21);

    // 입력 처리
    scanf("%s", yeondu);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%s", team_info[i].name);

    size_yeondu = strlen(yeondu);

    // 점수 계산
    for (i = 0; i < size_yeondu; i++) // 연두 이름에 등장하는 L, O, V, E 개수 계산
    {
        if (yeondu[i] == 'L')
            yeondu_L++;
        else if (yeondu[i] == 'O')
            yeondu_O++;
        else if (yeondu[i] == 'V')
            yeondu_V++;
        else if (yeondu[i] == 'E')
            yeondu_E++;
    }

    for (i = 0; i < N; i++)
    {
        size_team = strlen(team_info[i].name);
        L = O = V = E = 0;

        for (j = 0; j < size_team; j++) // 연두 이름에 등장하는 L, O, V, E 개수 계산
        {
            if (team_info[i].name[j] == 'L')
                L++;
            else if (team_info[i].name[j] == 'O')
                O++;
            else if (team_info[i].name[j] == 'V')
                V++;
            else if (team_info[i].name[j] == 'E')
                E++;
        }

        // 팀 이름에 등장하는 L, O, V, E와 연두 이름에 등장하는 L, O, V, E의 합 계산
        L += yeondu_L;
        O += yeondu_O;
        V += yeondu_V;
        E += yeondu_E;

        team_info[i].score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
    }

#ifdef DEBUG_MODE
    for (i = 0; i < N; i++)
        printf("%s : %d\n", team_info[i].name, team_info[i].score);
#endif  

    // 정렬
    qsort(team_info, N, sizeof(info), compar);

    // 정답 출력
    printf("%s\n", team_info[0].name);

    // 프로그램 종료
    return 0;
}