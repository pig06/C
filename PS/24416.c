#include <stdio.h>
#define MAX 40
int main(){
    int n,i;
    int code_1[MAX +1];
    code_1[0] = 0;
    code_1[1] = 1;
    code_1[2] = 1;

    scanf("%d" , &n);
    for (i = 3; i<=n;i++){
        code_1[i] = code_1[i-1] + code_1[i-2];
    }
    printf("%d %d\n" , code_1[n], n-2);
    return 0;
}