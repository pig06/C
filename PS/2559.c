#include <stdio.h>

#define SIZE 100000

int main()
{
    short arr[SIZE];
    int N,K;
    int i, max, sum = 0;
    int begin , end;

    scanf("%d %d" , &N, &K);
    for(i = 0;i < N; i++)
    {

        scanf("%hd" , &arr[i]);
    }

    for(i = 0; i < K; i++)
    {
        sum += arr[i];

    }

    max = sum;
    begin = 0;
    end = K;
    while(end < N)
    {

        sum = sum - arr[begin];
        begin++;

        sum += arr[end];
        end++;

        if(sum > max)
        {
            max = sum;
        }
        
        
    }

    printf("%d" , max);
    return 0;
}