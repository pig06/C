#include <stdio.h>
typedef unsigned long long ull;


#define SIZE 1000
int main(){
    const ull M = 1000000;
    const ull BRONZE = 1;
    const ull SILVER = BRONZE*M+1;
    const ull GOLD  = SILVER *M+1;

    ull score[SIZE + 1][5];
    int n,k;               //n 입력되는 국가 수 , k 순위를 알고싶은 국가의 번호
    int i , j;
    int a,b,c,d;
    int cnt;

    scanf("%d %d" , &n,&k);

    for (i = 1; i <= n; i++){

        scanf("%d %d %d %d" , &a,&b,&c,&d);
        score[a][0] = b;
        score[a][1] = c;
        score[a][2] = d;
        score[a][3] = b * GOLD+ c * SILVER+ d*BRONZE;
        score[a][4] = 0;
    }
    
    for (i = 1;i <= n; i++){
        cnt = 0;
        for (j = 1; j <= n; j++){
            if(score[i][3] < score[j][3]){
                cnt++;
            }
            
        }
        score[i][4] = cnt+1;         
    }
    



    printf("%lld\n" , score[k][4]);

    return 0;
}   