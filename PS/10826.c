#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10000

void calc_fib(int n);
char*sum_string(char str1[],char str2[]);

int main(){
    
    int n;
    scanf("%d" , &n);
    calc_fib(n);
    return 0;
}

void calc_fib(int n){
    int i;
    char fib[SIZE+1][SIZE+1];
    char str1[SIZE+1];
    char str2[SIZE+1];
    memset(fib,'\0',sizeof(char)*(SIZE +1)*(SIZE+1));
    memset(str1,'\0',sizeof(char)*(SIZE +1));
    memset(str2,'\0',sizeof(char)*(SIZE +1));

    for(i = 2;i<=n;i++){
        *(fib[i]) = sum_string(str1 , str2);
    }
    printf("%s\n",fib[n]);
    return;
}

char* sum_string(char str1[], char str2[]){
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    
    char result[SIZE+1];
    memset(result,'\0', sizeof(char)*(SIZE+1));
    int result_len = (str1_len > str2_len ? str1_len : str2_len) + 1;
    int carry = 0,i;

    for (i = result_len - 1; i>=0; i--){
        result[i] = atoi(str1[str1_len-1])
    }
}