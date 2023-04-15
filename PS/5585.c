#include <stdio.h>

#define budget 1000

int get_coins(int money);

int main()
{
    int price;
    int change;
    scanf("%d" , &price);
    change = budget - price;

    printf("%d\n" , get_coins(change));
    return 0;
}

int get_coins(int money)
{
    int num;
    int input = money;
    
    int coin[6] = {500 , 100 ,50, 10 ,5, 1};
    int i;

    for(i = 0; i< 6; i++)
    {
        if (input >= coin[i])
        {
            num += input / coin[i];
            input = input % coin[i];
        }
    }
    
    return num;
}