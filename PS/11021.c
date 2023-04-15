#include <stdio.h>

int main()
{
    int T, A , B, i;

    scanf("%d" , &T);

    for (i = 0; i< T; i++)
    {
        scanf("%d %d" , &A, &B);
        printf("Case #%d: %d\n" , i+1 , A+B);
    }

    return 0;
}