#include <stdio.h>

int main(){
    int cnt_a[46];
    int cnt_b[46];
    int k , i;
    scanf("%d" ,&k );

    cnt_a[0] = 1;
    cnt_a[1] = 0;
    cnt_b[0] = 0;
    cnt_b[1] = 1;
    
    for (i = 2; i <= k; i++){
        cnt_a[i] = cnt_a[i-1] + cnt_a[i-2];
        cnt_b[i] = cnt_b[i-1] + cnt_b[i-2];
    }

    printf("%d %d" , cnt_a[k], cnt_b[k] );
}