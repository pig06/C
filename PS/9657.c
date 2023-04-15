#include <stdio.h>
//기호상수ㄱ
#define MAX 1000
#define sk 0
#define cy 1

int main(){
    int win[MAX + 1];
    int n , i;
    scanf("%d" , &n);

    win[1] = sk; // 0 sk , 1 cy
    win[2] = cy;
    win[3] = sk;
    win[4] = sk;
    

    for(i = 5; i<= n; i++){
        if(win[i-1] == cy||win[i-3] == cy||win[i-4] == cy){
            win[i] = sk;
        }
        else win[i] = cy;
    }

    if(win[n] == sk){
        printf("SK\n");
    }
    else{
        printf("CY\n");
    }
    return 0;


}