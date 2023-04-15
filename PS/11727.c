#include <stdio.h>

int main(){
    int i,n;

    unsigned long long num[1001];
    num [1] = 1;
    num[2] = 3;
    scanf("%d" , &n);
    
    for (i = 3;i<= n;i++){
        num[i]= num[i-1] + 2* num[i-2];
        num[i] %= 10007;
    }

    printf("%lld" , num[n]%10007);
}