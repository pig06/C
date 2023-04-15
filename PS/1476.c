#include <stdio.h>

int main(){
    int year = 1;
    int E,S,M;
    int e =1, s =1 , m= 1;
    scanf("%d %d %d", &E, &S, &M);

    while (E != e|| S != s ||M != m)
    {
        year++;

       ++e > 15? e=1:e;
       ++s > 28? s=1:s;
       ++m > 19? m=1:m;
      
    }

    printf("%d\n", year);
    return 0;
    
}