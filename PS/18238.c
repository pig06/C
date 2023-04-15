// ZOAC 2

#include <stdio.h>
#include <string.h>

int abs(int num)
{
    return num > 0 ? num : num*-1;
}

int get_shortest(char a, char b)
// 문자 a에서 b까지 이르는데
// 이 둘 사이의 최단 경로의 길이를 반환
// get_shortest('A', 'Z') -> 1
{
    int path1; // 다이얼을 오른쪽으로 돌렸을 때 소요되는 시간
    int path2; // 다이얼을 왼쪽으로 돌렸을 때 소요되는 시간

    path1 = abs(b - a);
    path2 = abs(26 - path1);

    return path1 > path2 ? path2 : path1;
}

int main()
{
    char str[100+1];
    int size;
    int time = 0; // 다이얼을 가장 적게 돌렸을 때 소요되는 시간 (정답)
    int i;

    memset(str, '\0', sizeof(str));
    scanf("%s", str);
    size = strlen(str); // 문자열의 길이 = 문자의 개수

    // 계산
    time = get_shortest('A', str[0]);
    for(i=1; i<size; i++) 
        time += get_shortest(str[i-1], str[i]);

    printf("%d\n", time); // 정답 출력
    return 0;
}