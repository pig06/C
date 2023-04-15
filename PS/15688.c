#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int compar(const void * item1 , const void * item2)
{
    const int a = *((int *)item1);
    const int b = *((int *)item2);

    if (a < b)
        return -1;
    else if(a > b)
        return +1;
    else 
        return 0;
}
int main()
{
    int arr[MAX];
    int n;
    int i;
    scanf("%d", &n);
    for(i = 0;i < n; i++)
    {
        scanf("%d" , &arr[i] );
    }
    qsort(arr, n, sizeof(int), compar);

    for (i = 0; i < n; i++)
    {
        printf("%d\n" ,arr[i]);
    }
   
}