#include <stdio.h>

int convert(int num, int from, int to);
// 숫자 num에서 from을 전부 to로 바꾼다.

int main()
{
    int a, b;
    int min, max;

    scanf("%d %d", &a, &b);

    min = convert(a, 6, 5) + convert(b, 6, 5);
    max = convert(a, 5, 6) + convert(b, 5, 6);

    printf("%d %d\n", min, max);
    return 0;
}

int convert(int num, int from, int to)
{
    int input = num;
    int output = 0;
    int digits = 1; // 자릿수
    int digit;      // 현재 숫자

    // input을 구성하는 숫자 하나하나를 output에 옮겨놓음 (일의 자리부터)
    while(input != 0)
    {
        digit = input % 10;

        if(digit == from)
            digit = to;

        output += digit * digits;
        digits *= 10;
        input /= 10;
    }

    // input = 1357
    // Loop1: output = 7
    // Loop2: output = 57 (자릿수를 곱해서 더해야 함!)
    // Loop3: output = 357
    // Loop4: output = 1357

    return output;
}