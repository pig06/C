#include <stdio.h>

#define MAX 50000

int  min(int a,int b);

int main(){
    int input , i, j;
    int squares[MAX + 1];
    scanf("%d" ,&input);

    squares[0] = 0;
    squares[1] = 1;
    for (i = 1; i<= input; i++){
        squares[i] = 1+ squares[i - 1];

        for (j = 2; j*j<= i; j++){
            squares[i] = min(squares[i] , 1+squares[i-j*j]);
        }
    }
    printf("%d\n" , squares[input]);
    return 0;

}

int min(int a,int b){
    if (a<b) return a;
    return b;
}