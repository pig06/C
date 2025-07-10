#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int check47(int N){
    while(N>0){
        if(N%10 == 4 || N%10 == 7){
            N/=10;
        }
        else return FALSE;
    }
    return TRUE;
}

int main(){
    int N;

    // 1. 입력 처리
    scanf("%d", &N);

    // 2. 계산
    do{
        // 금민수인 경우
        if(check47(N)){
            // 3. 정답 출력
            printf("%d\n", N);
            break;
        }

    }while(--N);

    // 4. 프로그램 종료
    exit(EXIT_SUCCESS);
}