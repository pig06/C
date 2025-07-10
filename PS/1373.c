#define SIZE 1000000
#define OFFSET 48

#include <stdio.h>
#include <string.h>

int main()
{
    char input[SIZE + 1];
    char result[SIZE / 3 + 2];
    int len = 0;

    memset(input, '\0', SIZE + 1);
    memset(result, '\0', SIZE / 3 + 2);

    scanf("%s", input);
    len = strlen(input);

    int iidx = 0; // index of input
    int ridx = 0; // index of result

    if (len % 3 == 1)
    {
        printf("%d", input[0]-OFFSET);
        iidx = 1;
    }
    else if (len % 3 == 2)
    {
        printf("%d", (input[0] - OFFSET) * 2 + (input[1] - OFFSET) * 1);
        iidx = 2;
    }
    for (int i = 0; i < len / 3; i++)
    {
        printf("%d", ((input[iidx] - OFFSET) * 4) + ((input[iidx + 1] - OFFSET) * 2) + ((input[iidx + 2] - OFFSET) * 1));
        iidx += 3;
    }

    // 정답 반환
    printf("\n");

    return 0;
}