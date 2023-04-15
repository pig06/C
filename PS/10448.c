#include <stdio.h>

int main(){
    int T,K;
    int i , j, k;
    scanf("%d" , &T);

    int t[45];
    t[0] = 0;
    for (i = 1; i < 45;i++){
        t[i] = i * (i + 1) / 2;
    }

    int flag = 0;
    while (T--){
        scanf("%d" , &K);

        flag = 0;

        for (i = 1; i < 45; i++){
            for (j = 1; j < 45; j++){
                for (k = 1; k < 45; k++){
                    if (t[i] + t[j] + t[k] == K)
                    {
                        printf("1\n");
                        flag = 1;
                    }
                    if (flag == 1) break;
                }
                if (flag == 1) break;
            }
            if (flag == 1) break;
        }
        if (flag == 0){
            printf("0\n");
        }
    }
    return 0;

}