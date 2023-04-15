#include <stdio.h>

#define TRUE 1     // 참
#define FALSE 0    // 거짓
#define SIZE 10000 // 최댓값

int d(int n); // d(n)을 반환하는 함수

int main()
{
    int self_number[SIZE + 1]; // 1 ~ 10000의 셀프넘버 여부를 저장하는 배열
    int output, i;

    // 배열 초기화
    for (i = 1; i < SIZE + 1; i++)
        self_number[i] = TRUE;

    // 셀프넘버 계산
    for (i = 1; i < SIZE + 1; i++){
        output = d(i);
        if(output > SIZE)
            continue;   // 10,000을 넘어서는 값은 무시

        self_number[output] = FALSE;
    }

    // 결과 출력
    for (i = 1; i < SIZE + 1; i++)
    {
        if (self_number[i])
            printf("%d\n", i);
    }

    return 0;
}

int d(int n)
{
    int input = n;
    int result = n;

    while(input != 0)
    {
        result += input % 10; // 입력값의 1의 자리를 결과에 더함
        input /= 10;          // 입력값의 1의 자리를 절삭
    }

    return result;
}