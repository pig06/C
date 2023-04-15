#include <stdio.h>

// #define DEBUG_MODE

#define MAX_DISHES 30000 // 최대 접시수
#define MAX_TYPES 3000   // 최대 초밥 가짓수

#define TRUE 1  // 참
#define FALSE 0 // 거짓

int calc_types(int types[], int d)
{
    int cnt = 0; // 먹은 초밥의 가짓수(종류)
    int i;

    for (i = 1; i <= d; i++)
    {
        if (types[i] > 0)
            cnt++;
    }

    return cnt;
}

int main()
{
    int table[MAX_DISHES + 1]; // 초밥 컨베이어 벨트
    int types[MAX_TYPES + 1];  // 먹은 초밥의 개수
    int N;                     // 전체 초밥의 개수
    int d;                     // 최대 초밥 번호 (초밥의 가짓수)
    int k;                     // 연속해서 먹어야 하는 초밥의 개수
    int c;                     // 쿠폰 번호

    int i, front, back;
    int max_types = 0;  // 현재까지 먹은 초밥의 최대 가짓수
    int curr_types = 0; // 현재까지 먹은 초밥의 가짓수

    // 입력 처리
    scanf("%d %d %d %d", &N, &d, &k, &c);
    for (i = 0; i < N; i++)
        scanf("%d", &table[i]);

    // 초기화
    for (i = 1; i <= d; i++)
        types[i] = 0;

    front = 0;
    back = k - 1;

    for (i = front; i <= back; i++)
        types[table[i]]++;

    max_types = calc_types(types, d); // 먹은 초밥의 가짓수를 계산

    // 투 포인터
    while(front < N)
    {
        types[table[front]]--;
        front++;

        back++;
        back %= N;
        types[table[back]]++;

        curr_types = calc_types(types, d);

        // 쿠폰 계산
        if(table[front-1] == c && types[c] == 0)
            curr_types++;
        else if(table[(back+1) % N] == c && types[c] == 0)
            curr_types++;
        else if(max_types < d && types[c] == 0)
            curr_types++;

        // 최댓값 비교
        max_types = curr_types > max_types ? curr_types : max_types;
    }

    // 정답 출력
    printf("%d\n", max_types);

    return 0;
}