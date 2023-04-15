#include <stdio.h>
#define MAX 10000

int abs (int num)
{
    return  num > 0 ? num : num*-1;
}

int main()
{
    int N;
    int round1[MAX];
    int round2[MAX];
    int result = 0;
    int sum = 0;
    int i;

    scanf("%d" , &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d" , &round1[i]);
        result += abs(round1[i]);
    }
    for(i = 0; i < N; i++)
    {
        scanf("%d" , &round2[i]);
        result += abs(round2[i]);
    }

    printf("%d\n" , result);
    return 0;
}