#include <stdio.h>
#include <stdlib.h>

int get_score(char arr1[35], char arr2[35]){
    int score=0;

    for(int i=0; i<35; i++){
        if(arr1[i] != arr2[i])
            score++;
    }

    return score;
}

int main(){
    char arr[50][35];
    int N;
    int ans1, ans2;

    // 1. 입력처리
    scanf("%d", &N);

    for(int i=0; i<N;i++){
        for(int j=0; j<35; j+=7)
            scanf("%s", &arr[i][j]);
    }

    // 2. 비교
    int score=0;
    int max_score=36;

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            score = get_score(arr[i], arr[j]);

            if(score < max_score){
                max_score = score;
                ans1 = i;
                ans2 = j;
            }
        }

    }

    // 3. 정답 출력
    printf("%d %d\n", ans1+1, ans2+1);

    exit(EXIT_SUCCESS);


    // Debug
    // for(int i=0; i<N;i++){
    //     for(int j=0; j<35; j++)
    //         printf("%c", arr[i][j]);
    //     printf("\n");
    // }
}
