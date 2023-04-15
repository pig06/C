#include <stdio.h>
#define MAX 1000000
int main(){
    int N,M;
    int i, a = 0 , b = 0 , cnt = 0;
    int A[MAX];
    int B[MAX];
    int result[MAX*2];
    scanf("%d %d" ,&N , &M );

    for (i = 0; i < N; i++){
        scanf("%d" , &A[i]);
    }
    
    for (i = 0; i < M; i++){
        scanf("%d" , &B[i]);
    }

    while(cnt < N+M){
        if(A[a] < B[b]){
            result[cnt] = A[a];
            a++;
            cnt++;
        }
        else {
        
            result[cnt] = B[b];
            b++;
            cnt++;
        }
        if (a >= N){
            while(cnt < N+M){
                result[cnt] = B[b];
                b++;
                cnt++; 
            }
        }
        else if(b >= M){
            while(cnt < N+M){
                result[cnt] = A[a];
                a++;
                cnt++; 
            }
        }       
    }
    for (i = 0; i < N+M; i++){
        printf("%d " , result[i]);
    }
   

}