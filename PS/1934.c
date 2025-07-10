#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int c = a%b;

    if(c == 0)return b;
    else return gcd(b,c);
}

int main()
{
    int T,a,b,LCM;
    scanf("%d" , &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d" , &a,&b);
        LCM = a*b/gcd(a,b);
        printf("%d\n" , LCM);
    }
   
    exit(EXIT_SUCCESS);
}