#include <stdio.h>

int main(){
    int students; // 학생수
    int class[1000][10]; // 학생수 * 반 정보
    int cnt[1000] = {0}; // 같은반이 되어본 친구의 수

    // 1. 입력 처리
    scanf("%d", &students);

    for(int i=0; i<students; i++){
        for(int j=0; j<5; j++)
            scanf("%d", &class[i][j]);
    }



    // 2. 계산
    for(int i=0; i<students; i++){
        for(int j=i+1; j<students; j++){
            for(int k=0; k<5; k++){
                if(class[i][k] == class[j][k]) {
                    cnt[i]++;
                    cnt[j]++;
                    break;
                }
            }
        }
    }



    // 3. 정답 출력
    int max_cnt=0, max_student=0;

    for(int i=0; i<students; i++){
        if(max_cnt < cnt[i]){
            max_cnt = cnt[i];
            max_student = i;
        }
    }

    printf("%d\n", max_student+1);

    return 0;
}