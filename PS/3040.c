#include <stdio.h>

void print(int member[9], int i,int j);
int main(){
    int i,sum = 0 ,j;
    int member[9];
    for (i = 0; i < 9;i++){
        scanf("%d" , &member[i]);
        sum += member[i];
    }

    for (i = 0; i< 9;i++){
        for (j = 0; j < 9; j++){
            if (i == j) continue;

            if (sum - member[i] - member[j] == 100){
                print(member,i,j);
                return 0;
            }
        }
    }

    
}

void print(int member[9], int i,int j){
    int idx;
    for (idx = 0;idx<9;idx++){
        if (idx == i || idx == j)
        {
            continue;
        }

        printf("%d\n", member[idx]);
    }
}