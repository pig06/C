#include <stdio.h>

int main()
{
    int t= 1;
    int l,p,v;
    int result;
    while(1)
    {
        scanf("%d %d %d", &l , &p, &v);
        
        if(l == 0 && p==0 && v==0 ){
            return 0;
        }
            
        result = (v/p)*l; + (v%p);
        printf("Case %d: %d\n", t, result);
        ++t;
    }
   
}