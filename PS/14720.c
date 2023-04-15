#include <stdio.h>

#define STRAWBERRY 0
#define CHOCO 1
#define BANANA 2

int main()
{
    // 딸기 -> 초코 -> 바나나 -> 딸기

    int cnt_milk = 0; // 먹은 우유의 수 (정답)
    int N;            // 우유 가게의 수
    int curr_milk;    // 현재 위치한 우유 가게의 종류
    int eatable = STRAWBERRY; // 현재 내가 먹을 수 있는 우유의 종류
    int i;

    // 입력 처리
    scanf("%d", &N);

    // 계산
    for(i=0; i<N; i++)
    {
        scanf("%d", &curr_milk);

        if(curr_milk == eatable) // 현재 위치한 우유 가게에서 내가 사먹을 수 있는 경우
        {   
            cnt_milk++;
            eatable++;
            eatable %= 3;
        }
    }

    // 정답 출력
    printf("%d\n", cnt_milk);

    return 0;
}