#include <stdio.h>
#include <stdlib.h>

int main(){
    long long N;
    scanf("%lld", &N);
    printf("%lld", N*(N-1)/2*(N+1));
    exit(EXIT_SUCCESS);
}


// (N=2) answer= 3                = 3
// (N=3) answer= 4 + 8            = 12
// (N=4) answer= 5 + 10 + 15      = 30
// (N=5) answer= 6 + 12 + 18 + 24 = 60
// (N=6) answer= 7 + 14 + 21 + 28 + 35 = 
// (N=x) answer= (x+1) + 2(x+1) + 3(x+1) + ... + (x-1)(x+1)
//             = (1 + 2 + 3 + ... + x-1) * (x+1)
//             = (x)(x-1)/2              * (x+1)