#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(){
    int a,b,cnt = 0,result = 0;   
    scanf("%d %d" , &a ,&b);
    for (int i = 1; i <= MAX; i++){
        for (int j = 0; j < i; j++){
            if(cnt>b){
                printf("%d" , result);
                exit(EXIT_SUCCESS);
            }
            cnt++;
            if(cnt>=a && cnt<=b){
                result+=i;
            }
        }
    }
    exit(EXIT_FAILURE);
   
}