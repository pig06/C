#include <stdio.h>

int get_difference(int x);

int main(){
    int sum = 0;
    int i, input;

    for (i = 0; i< 10; i++){
        scanf("%d" , &input);

        sum += input;
        if (100 <= sum){
            if (get_difference(sum) <= get_difference(sum-input)){
                printf("%d" , sum);
                return 0;
            }
            else {
                printf("%d" , sum-input);
                return 0;
            }
        }
    }
    printf("%d" , sum);
}



int get_difference(int x){
    if(x >= 100){
        return x - 100;
    }
    else return 100 - x;
}