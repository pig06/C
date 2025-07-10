#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int REV(int input){
    int result = 0;
    int digits = log10(input)+1;
    for(int i=0; i<digits; i++){
        result+= input%10 * pow(10,digits-i-1);
        input /= 10;
    }
    //printf("result: %d\n" , result);
    return result;
}

int main(){
    int x,y;
    scanf("%d %d" , &x, &y);

    printf("%d\n" , REV(REV(x) + REV(y)));

    return EXIT_SUCCESS;
}