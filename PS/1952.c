#include <stdio.h>
#include <stdlib.h>

#define HORIZON  0 // 가로
#define VERTICAL 1 // 세로

int main(){
    int M; // 행의 개수 (가로)
    int N; // 열의 개수 (세로)

    int answer=0;   // 정답
    int dir=HORIZON;// 현재 진행 방향

    scanf("%d %d", &M, &N);

    while(M != 0 && N != 0){

        // 가로 방향으로 진행하는 경우
        if(dir == HORIZON){
            M--;
            dir = VERTICAL;
            answer++;
        }

        // 세로 방향으로 진행하는 경우
        else if (dir == VERTICAL){
            N--;
            dir = HORIZON;
            answer++;
        }
        else
            exit(EXIT_FAILURE);
    }

    printf("%d\n", answer-1);

    exit(EXIT_SUCCESS);
}