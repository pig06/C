#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char chair[MAX + 1];
    int N;
    int i;
    int cnt_user = 0;
    int size_chair;
    scanf("%d" , &N);
    scanf("%s" , chair);

    cnt_user = 1;
    size_chair =strlen(chair);
    for (i = 0; i < size_chair; i++)
    {
        if (chair[i] == 'S'){
            cnt_user++;
        }
        else
        {
            i++;
            cnt_user++;
        }
        
    }
    if (N < cnt_user){
        printf("%d" , N);
    }
    else printf("%d" , cnt_user);


   

    return 0;
}
