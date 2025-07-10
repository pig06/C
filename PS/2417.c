#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedef long long int lli;

int main(){
    lli n;

    scanf("%lld", &n);

    lli min=0;
    lli max=4294967296; // 2^32
    lli mid;
    lli answer;

    int flag = FALSE;

    while(min < max){
        mid = (min+max) / 2;

        if(mid*mid == n){
            answer = mid;
            flag = TRUE;
            break;
        }
        else if(mid*mid > n)
            max = mid-1;
        else
            min = mid+1;

        // printf("min: %lld\n", min);
        // printf("max: %lld\n", max);
        // printf("mid: %lld\n\n", mid);
    }

    if(!flag)
        answer = mid+1;

    printf("%lld\n", answer);

    exit(EXIT_SUCCESS);
}