#include <stdio.h>

int main(){
    int N,L,D;
    int time=0;
    scanf("%d %d %d" , &N,&L,&D);

    for(int i = 0;i<N-1;i++){
        time+=L;
        for(int j =0;j<5;j++){
            time++;
            if(time%D==0){
                
                printf("%d\n", time);
                return 0;
            }
        }
    }

    printf("%d\n", time*((time /D)+1));

    return 0;

}