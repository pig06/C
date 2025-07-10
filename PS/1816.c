#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
#define true 1
#define false 0

int prime_factorization(unsigned long long S)
{
    for(int i = 2;i<= S;i++) {
        if(S%i==0) {
            if (MAX >= i)
                return false;
        }

        if( i > MAX)
            return true;
    }

    return false;
}

int main()
{
    int N;
    unsigned long long S;

    scanf("%d" , &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%lld" , &S);
        if(prime_factorization(S))
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }

    exit(EXIT_SUCCESS);
}
