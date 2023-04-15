#include <stdio.h>

#define MAX 80

int main(){
    unsigned long long num[MAX + 1];
    int n , i;
    unsigned long long result;

    num[0] = 0;
    num[1] = 1;
    scanf("%d" , &n);

    for (i = 2;i <= n; i++){
        num[i] = num[i-2] + num[i-1];
        //printf("%d" , num[i]);
    }

    result = (num[n] + num[n-1] + num[n])*2;

    printf("%lld" , result);
}