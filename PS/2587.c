#include <stdio.h>
#include <stdlib.h>
#define DEBUG_MODE

int compare(const void*a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int i;
    int num[5];
    int Average = 0;

    for(i = 0; i < 5; i++)
    {
        scanf("%d" , &num[i]);
        Average += num[i];
    }
    Average /= 5;

    qsort((int*)num,5,sizeof(int),compare);
#ifdef DEBUG_MODE
    printf("after Sort\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }
       
    printf("\n");
#endif
    
    printf("%d\n%d" , Average , num[2]);


    return 0;
}