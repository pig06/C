#include <stdio.h>

int main()
{
    int N;
    int cycles = 0;
    int prev_val, next_val;
    scanf("%d" , &N);

    prev_val = N;
    next_val = -1;
    while (next_val != N)
    {
        next_val = prev_val % 10 * 10;

        next_val += (prev_val/10 + prev_val%10) %10;

        prev_val = next_val;

        cycles++;
    }
    

    printf("%d\n" , cycles);
}