#include <stdio.h>
#include <stdlib.h>

int main(){
    int T,A,B;
    scanf("%d" ,&T);
    for(int i = 0; i < T;i++){
        scanf("%d %d", &A , &B);
        printf("%d\n" , A+B);
    }
    exit(EXIT_SUCCESS);
}