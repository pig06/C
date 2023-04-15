#include <stdio.h>

int main()
{
    int n, v;
    int i, cost=0, max=0;

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &v);
        cost += v;

        if(max < v)
            max = v;
    }

    printf("%d\n", cost-max);

    return 0;
}