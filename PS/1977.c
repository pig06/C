#include <stdio.h>
#include <math.h>


int main(){
    int m,n, min, sum = 0,num = 0, i;

    scanf("%d", &m);
    scanf("%d" , &n);

    for (i = m; i<=n; i++){
        if (sqrt(i) == (int)sqrt(i)){
            sum+=i;
            num++;
            if (num == 1){
                min = i;
            }
        }
    }
    if (num == 0){
        printf("-1");
    }
    else printf("%d\n%d" , sum, min);
}