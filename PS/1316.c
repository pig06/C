#include <stdio.h>
#include <string.h>

int cnt (char arr[], int len);

int main()
{
    int n, i , sum;

    scanf("%d", &n);
    char arr [101];
    for (i = 0; i< n; i++)
    {
        scanf("%s" , &arr);
        sum +=  cnt (arr , strlen(arr));
    }

    printf("%d" , sum);
}

int cnt (char arr[] ,int len)
{
    int i , y ;
    for (i = 0; i < len; i++){
        for (y = 0; y < len; y++){
            if (arr[i] == arr[y])
            {

                if (i - y < -1 || i - y > 1)
                {
                    return 0;
                }
            }
        } 
    }   
    return 1;
}