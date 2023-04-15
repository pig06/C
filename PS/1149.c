#include <stdio.h>

#define MAX 1000

int N;
int input[MAX][3];
int cost[MAX][3];

void process_input();
void calc_cost();
int min(int a, int b);

int main(){
    int min_cost;
    process_input();
    calc_cost();
    min_cost = cost[N-1][0] > cost[N-1][1]? cost[N-1][1] : cost[N-1][0];
    min_cost = min_cost > cost[N-1][2]? cost[N-1][2] : min_cost;
    printf("%d\n" , min_cost);
}


void process_input(){
    scanf("%d" , &N);

    for (int i=0;i<N;i++){
        scanf("%d %d %d" , &input[i][0] , &input[i][1], &input[i][2]);
    }
}
void calc_cost(){
    int i ;
    for(i = 0;i< 3; i++){
        cost[0][i] = input[0][i];

    }
    for (int i =1; i < N; i++){
        for (int p = 0;p <3 ;p++){
            cost[i][p] = input[i][p] + min(cost[i-1][(p+1)%3], cost [i-1][(p+2)%3]);
        }
    }
}
int min(int a, int b){
    if(a>b) return b;
    return a;
    
}