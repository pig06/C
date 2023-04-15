#include <stdio.h>

int main(){
    unsigned long long FIB[90];
    FIB[0] = 0;
    FIB[1] = 1;
    int i, n;
    scanf("%d" , &n);
    for (i = 2; i<= n;i++){
        FIB[i] = FIB[i - 2] + FIB[i - 1];
    }
    printf("%lld" , FIB[n]);
}