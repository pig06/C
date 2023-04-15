#include <stdio.h>

int main()
{
    int A, B, C;
    int left, right;

    // EOF : End of File
    // while(scanf("%d %d %d", &A, &B, &C) == 3)
    // {
    //     left = B - A - 1;
    //     right = C - B -1;
    //     printf("%d\n", left>right?left:right);
    // }

    while(scanf("%d %d %d", &A, &B, &C) != EOF)
    {
        left = B - A - 1;
        right = C - B -1;
        printf("%d\n", left>right?left:right);
    }

    return 0;
}