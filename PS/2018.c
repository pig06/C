#include <stdio.h>

int main()
{
    int N;
    int cnt = 0;
    int sum = 1;
    int front = 1 , back = 1;

    scanf("%d" , &N);

    while(front  <= back && back <= N)
    {
        if(sum < N)
        {
            sum += ++back;
        }
        else if(sum > N)
        {
            sum -= front++;
        }
        else
        {
            cnt++;
            sum -= front++;
        }
    }
    printf("%d\n" , cnt);
    return 0;
}