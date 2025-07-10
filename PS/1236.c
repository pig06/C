#include <stdio.h>

#define SIZE 50
#define TRUE 1
#define FALSE 0

// 해당 가로열에 경비원이 배치되어 있으면 TRUE / 없으면 FALSE 리턴
int isOccupiedRow(char map[SIZE][SIZE], int n, int m, int searchRow);

// 해당 세로열에 경비원이 배치되어 있으면 TRUE / 없으면 FALSE 리턴
int isOccupiedCol(char map[SIZE][SIZE], int n, int m, int searchCol);

// 맵 출력
void printMap(char map[SIZE][SIZE], int n, int m);

// 메인함수
int main(){
    char map[SIZE][SIZE];
    int n, m;
    int answer = 0;

    // 1. 입력 처리
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        fflush(stdin);

        for(int j=0; j<m; j++)
            scanf("%c", &map[i][j]);
        fflush(stdin);
    }

    printMap(map, n, m);

    // 2. 계산
    
    // 2-1. 가로 X 세로 경비원이 없는 경우의 경비원 배치
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( !isOccupiedRow(map, n, m, i) && !isOccupiedCol(map, n, m, j)){
                map[i][j] = 'X';
                answer++;
                break;
            }

            if( isOccupiedRow(map, n, m, i) )
                break;
        }
    }


    // 2-2. 가로에 없는 경우의 경비원 배치
    for(int i=0; i<n; i++){
        if( !isOccupiedRow(map, n, m, i) ){
            map[i][0] = 'X';
            answer++;
        }
    }


    // 2-3. 세로에 없는 경우의 경비원 배치
    for(int j=0; j<m; j++){
        if( !isOccupiedCol(map, n, m, j) ){
            map[0][j] = 'X';
            answer++;
        }
    }


    // 3. 정답 출력
    printf("%d\n", answer);
    printMap(map, n, m);

    return 0;
}

int isOccupiedRow(char map[SIZE][SIZE], int n, int m, int searchRow){
    for(int j=0; j<m; j++){
        if(map[searchRow][j] == 'X')
            return TRUE;
    }

    return FALSE;
}

int isOccupiedCol(char map[SIZE][SIZE], int n, int m, int searchCol){
    for(int i=0; i<n; i++){
        if(map[i][searchCol] == 'X')
            return TRUE;
    }

    return FALSE;
}

void printMap(char map[SIZE][SIZE], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            printf("%c",map[i][j]);
        
        printf("\n");
    }

    printf("\n");
}
