#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(char str1[], char str2[]);

int main(){
    char str1[10] = "1234";
    char str2[10] = "4567";
    sum(str1,str2);
    return 0;
}

void sum(char str1[], char str2[])
{
    char result[11];
    memset(result,'\0' , sizeof(char) * 11);
    int result_len = strlen(str1) + 1;
    int str1_len = strlen(str1);
    int str1_len = strlen(str2);
    int i,carry = 0;
    int partial
}