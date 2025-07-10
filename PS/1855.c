#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int main()
{
    int K;
    char str[MAX+1];

    scanf("%d" , &K);
    scanf("%s", str);

    int x = strlen(str)/K;

    char table[x][K];

    for(int i = 0;i < x;i++ )
    {
        if(i%2==0)
        {
            for(int j = 0; j < K; j++)
            {
                table[i][j] = str[i*K+j];
            }
        }
        else
        {
            for(int j = 0; j < K; j++)
            {
                table[i][j] = str[i*K+K-1-j];
            }
        }
    }
    
    for(int i = 0; i < K;i++)
    {
        for (int j = 0;j < x; j++)
        {
            printf("%c", table[j][i]);
        }
    }
    exit(EXIT_SUCCESS);


}