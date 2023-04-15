#include <stdio.h>
#define HOURS 24

int main()
{
    int A; // 한 시간동안 일을 했을 때, 쌓이는 피로도
    int B; // 한 시간동안 일을 했을 때, 처리된 일의 양
    int C; // 한 시간동안 휴식을 했을 때, 제거되는 피로도
    int M; // 피로도의 상한선

    int work=0;    // 처리한 일의 총량
    int fatigue=0; // 쌓인 피로도의 총량
    int i;

    scanf("%d %d %d %d", &A, &B, &C, &M);

    // 예외 처리
    if(A > M)
    {
        printf("0\n");
        return 0;
    }

    // 계산
    for(i=0; i<HOURS; i++)
    {
        if(fatigue + A <= M) // 일을 해야하는 경우
        {
            work += B;
            fatigue += A;
        }
        else // 휴식을 해야하는 경우
        {
            fatigue -= C;
            if(fatigue < 0)
                fatigue = 0;
        }
    }

    // 정답 출력
    printf("%d\n", work);

    return 0;
}