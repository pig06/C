#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define true 1
#define false 0

int main(){
    int len, result;
    char arr[MAX];

    while(scanf("%s" , arr) && arr[0] != '0'){
        result = true;
        len = strlen(arr);
        for(int i = 0; i < len/2;i++){
            if(arr[i] != arr[len-1-i]){
                printf("no\n");
                result = false;
                break;
            }
        }
        if(result){
            printf("yes\n");
        }
    }
    
    exit(EXIT_SUCCESS);
}