#include <stdio.h>

#define MAX 100

int main(){
    unsigned long long padovan[MAX+1];
    int T,n,i;
    scanf("%d" , &T);
    padovan[1] = padovan[2] = padovan[3] = 1;
    for (i = 4; i<=MAX;i++){
        padovan[i] = padovan[i-2] + padovan[i - 3];
    }
    while (T--)
    {
        scanf("%d" , &n);
        printf("%lld\n" , padovan[n]);
    }
    return 0;
}