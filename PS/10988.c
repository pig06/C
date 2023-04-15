#include <stdio.h>
#include <string.h> // strlen(), memset() Function

#define MAX 100 + 1
#define TRUE  1
#define FALSE 0

int main()
{
    char str[MAX];
    int size;
    int check = TRUE; // 펠린드롬인지 아닌지에 대한 여부를 저장하는 변수
    int i;

    // 배열 초기화
    memset(str, '\0', sizeof(char)*MAX);

    // 입력 처리
    scanf("%s", str);
    size = strlen(str);

    for(i=0; i<size/2; i++)
    {
        if(str[i] != str[size-1-i])
        {
            check = FALSE;
            break;
        }
    }

    if(check)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}