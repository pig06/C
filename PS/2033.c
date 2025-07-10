#include <stdio.h>
#include <stdlib.h>


// Function Prototype (함수 전방선언)
int f_round(int num, int digit);  // 컴파일러에 함수의 존재를 "대강" 알려주는 용도


// Main Function
int main(){
    int N;
    int digit=1; // 반올림할 현재 자릿수

    scanf("%d", &N);

    // Exception Handling
    if(N < 10){
        printf("%d\n", N);
        exit(EXIT_SUCCESS);
    }

    while(digit*10 <= N){
        N = f_round(N, digit); // N을 digit자리에서 반올림 한 결과를 반환
        digit *=10;
    }

    printf("%d\n", N);

    exit(EXIT_SUCCESS);
}


// Function Implementation
int f_round(int num, int digit){

    int std = num / digit % 10; // 올림/버림을 판단할 기준

    // 버림
    if(std < 5){
        num /= digit*10;
        num *= digit*10;
    }
    // 올림
    else{
        num /= digit*10;
        num++;
        num *= digit*10;
    }

    return num;
}