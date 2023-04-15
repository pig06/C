#include <stdio.h>

int main()
{
    int i , j;
    int N ,M , cnt, sum;
    int arr[10000];
    scanf("%d %d" , &N , &M);
    for(i = 0; i< N; i++)
    {
        scanf("%d" , &arr[i]);
    }
    for(i = 0; i < N; i++)
    {
        sum = arr[i];
        if(sum == M)
        {
            cnt++;
            continue;
        }
        else if (sum > M) continue;
        for(j= i+1; j < N; j++)
        {
            sum += arr[j];
            if (sum == M)
            {
                cnt++;
                break;
            }
            else if(sum > M) break;
        }
    
    }
    printf("%d" , cnt);
}