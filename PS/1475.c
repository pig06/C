#include <stdio.h>
#include <math.h>

int main(){
    int input;
    int num[10];
    int i;
    int max=-1;
    scanf("%d", &input);

    for(i=0;i<10;i++)
        num[i] = 0;

    while(input != 0){
        num[input%10]++;
        input /= 10;
    }
    // 숫자 개수 파악 완료, num 배열에 입력 완료

    for(i=0;i<10;i++){
        if(i == 6 || i ==9)
            continue;
        if(num[i] > max)
            max = num[i];
    }
    // 6, 9를 제외한 숫자들 중 가장 많이 존재하는 숫자 개수 파악 완료

    num[6] = ceil(  (double)((double)(num[6] + num[9]) / (double)2)   );
    // 6과 9를 표현할 수 있는 숫자 세트 수 계산

    if(max > num[6])
        printf("%d\n", max);
    else
        printf("%d\n", num[6]);

    return 0;
}