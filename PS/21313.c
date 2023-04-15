#include <stdio.h>

int main()
{
    int n;
    int i;
    scanf("%d" , &n);
    for(i = 0; i< n/2; i++)
    {
        printf("1 2 ");
    }
    if(n%2!=0)
    {
        printf("3");
    }

    return 0;
}