#include <stdio.h>

int main(){
    int input[5];
    int answer = 1;
    int i = 1;
    int cnt = 0;
    for(int i=0; i<5; i++)
        scanf("%d", &input[i]);
    
    while(1)
    {
        for (int j = 0; j < 5; j++){
            if(i % input[j] == 0) cnt++;
        }
        if(cnt >= 3){
            break;
        }
        cnt = 0;
        i++;
    }
    answer = i;
    printf("%d\n", answer);
    return 0;
}