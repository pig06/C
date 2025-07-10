#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OFFSET 48
int main(){

    char input[11];
    int input_len;

    scanf("%s", input);
    input_len = strlen(input);

    for(int i=1; i<input_len; i++){
        int head_sum = 1; // 앞부분 자리의 곱
        int tail_sum = 1; // 뒷부분 자리의 곱

        for(int j=0; j<i; j++){
            head_sum *= input[j] - OFFSET;
        }

        for(int j=i; j<input_len; j++){
            tail_sum *= input[j] - OFFSET;
        }

        if(head_sum == tail_sum) {
            printf("YES\n");
            return EXIT_SUCCESS;
        }

    }

    printf("NO\n");
    return EXIT_SUCCESS;
}