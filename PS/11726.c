#include <stdio.h>

int main(){
    int i,n;

    unsigned long long num[1001];

    scanf("%d" , &n);
    num[0] = 0;
    num[1] = 1;
    num[2] = 2;

    for(i = 3; i<=n;i++){
        num[i] = num[i-1] + num[i-2];
        num[i] = num[i] % 10007;
    }
    

    printf("%lld" , num[n]%10007);
}