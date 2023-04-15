#include <stdio.h>
#include <string.h>

#define SIZE 16

int calc_time(char ch); // 문자 ch를 입력받아서 다이얼을 돌리는데 소요되는 시간을 리턴하는 함수

int main(){
    char input[SIZE];
    int len;
    int i;
    int time=0;

    scanf("%s", input);  // 배열의 이름은 곧 첫 번째 원소의 주솟값
    len = strlen(input); // len : input 문자열의 길이

    for(i=0;i<len;i++)
    {
        time += calc_time(input[i]);
    }

    printf("%d\n", time);
    return 0;
}

int calc_time(char ch)
// calc_time('A') = 3
// calc_time('K') = 6
// calc_time('V') = 9
{

}