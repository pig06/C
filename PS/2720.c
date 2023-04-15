#include <stdio.h>

#define QUARTER 25
#define DIME    10
#define NICKEL  5
#define PENNY   1

int main()
{
    int T;           // 테스트 케이스 수
    int change;      // 거슬러 줘야 하는 거스름 돈의 액수

    int cnt_quarter; // 거스름돈에서 쿼터 동전의 개수
    int cnt_dime;    // 거스름돈에서 다임 동전의 개수
    int cnt_nickel;  // 거스름돈에서 니켈 동전의 개수
    int cnt_penny;   // 거스름돈에서 페니 동전의 개수

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &change);

        cnt_quarter = cnt_dime = cnt_nickel = cnt_penny = 0; // 동전 개수 초기화

        if(change >= QUARTER)// 남은 change가 25원 이상인 경우
        {
            cnt_quarter = change / QUARTER;
            change -= (cnt_quarter * QUARTER);
            // change %= QUARTER;
        }
        
        if(change >= DIME)// 남은 change가 10원 이상인 경우
        {
            cnt_dime = change / DIME;
            change -= (cnt_dime * DIME);
        }
        
        if(change >= NICKEL)// 남은 change가 5원 이상인 경우
        {
            cnt_nickel = change / NICKEL;
            change -= (cnt_nickel * NICKEL);
        }
        
        if(change >= PENNY)// 남은 change가 1원 이상인 경우
        {
            cnt_penny = change / PENNY;
            change -= (cnt_penny * PENNY);
        }

        printf("%d %d %d %d\n", cnt_quarter, cnt_dime, cnt_nickel, cnt_penny);
    }

    return 0;
}