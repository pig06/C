#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

// Global Array
const char DIAL[8][4]={
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'Q', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y', 'Z'}
};

// Function Prototype
int get_push_time(char c);
int get_wait_time(char c, char prev);

// Main Function
int main(){
    int p; // 버튼을 한 번 누르는데 걸리는 시간
    int w; // 같은 그룹에 속한 버튼을 누르는데 대기하는 시간
    char input[SIZE]; // 입력 문자열
    int size_input;
    int answer=0;

    scanf("%d %d", &p, &w);
    scanf("%s", input);
    size_input = strlen(input);

    for(int i=0; i<size_input; i++){
        answer += get_push_time(input[i]) * p;

        if(i > 0)
            answer += get_wait_time(input[i], input[i-1]) * w;
    }

    printf("%d\n", answer);

    exit(EXIT_SUCCESS);
}


// Function Implementation
// 버튼을 누르는데 소요되는 횟수를 반환
int get_push_time(char c){
    if(c == ' ')
        return 1;

    int output;
    for(int i=0; i<8; i++){
        output=0;
        for(int j=0; j<4; j++){
            output++;

            if(c == DIAL[i][j])
                return output;
        }
    }

    // Exception
    exit(EXIT_FAILURE);
}

// Function Implementation
// 버튼을 누르는데 소요되는 '대기'횟수를 반환
int get_wait_time(char c, char prev){
    if(c == ' ')
        return 0;

    int cnt;
    for(int i=0; i<8; i++){

        cnt=0;
        for(int j=0; j<4; j++){
            if(DIAL[i][j] == c || DIAL[i][j] == prev)
                cnt++;
        }

        // 대기시간이 필요한 경우
        if(cnt == 2)
            return 1;
    }

    // 대기시간이 필요없는 경우
    return 0;
}