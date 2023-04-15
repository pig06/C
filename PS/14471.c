
// #define DEBUG_MODE

#include <stdio.h>
#include <stdlib.h> // qsort() Function

#define MAX 1000 // 포인트 카드의 최대 개수

// 원소의 타입
typedef struct card{
    int wins;  // 당첨 도장의 개수
    int loses; // 꽝 도장의 개수
}card;

// 비교 함수 (내림차순; Descending Order)
int compare(const void* a, const void* b)
{
    if(((card *)a)->wins < ((card *)b)->wins) // a가 b보다 작은 경우 (뒤쳐지는 경우)
        return 1;
    else if(((card *)a)->wins == ((card *)b)->wins) // a와 b가 같은 경우
        return 0;
    else
        return -1;
}

int main()
{
    int N; // 필요한 당첨 도장의 최소 개수
    int M; // 포인트 카드의 수   (M-1 : 필요한 경품의 최소 개수)
    card cards[MAX];

    int i;
    int cost = 0;  // 필요한 최소 비용 (정답)
    int gifts = 0; // 현재까지 교환한 경품의 수

    // 입력 처리
    scanf("%d %d", &N, &M);
    for(i=0; i<M; i++)
        scanf("%d %d", &cards[i].wins, &cards[i].loses); // 당첨 도장의 수, 꽝 도장의 수

    // 정렬
    qsort(cards, M, sizeof(card), compare);

#ifdef DEBUG_MODE
    for(i=0; i<M; i++)
        printf("%d %d\n", cards[i].wins, cards[i].loses);
#endif

    // 필요한 최소 비용 계산
    for(i=0; i<M; i++)
    {
        if(gifts == M - 1)
            break;

        if(cards[i].wins < N) // 당첨 도장이 모자른 경우
            cost += N - cards[i].wins;

        gifts++;
    }

    // 정답 출력
    printf("%d\n", cost);
    return 0;
}
