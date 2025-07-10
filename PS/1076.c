#include <stdio.h>
#include <string.h>

typedef struct resist_dict{
    char color[10]; // 색
    int value;      // 값
    long times;     // 곱
}resist_dict;

int main(){
    char input_1[10];
    char input_2[10];
    char input_3[10];
    long result=0;

    resist_dict resist[10];
    strcpy(resist[0].color, "black" ); resist[0].value = 0; resist[0].times=1;
    strcpy(resist[1].color, "brown" ); resist[1].value = 1; resist[1].times=10;
    strcpy(resist[2].color, "red"   ); resist[2].value = 2; resist[2].times=100;
    strcpy(resist[3].color, "orange"); resist[3].value = 3; resist[3].times=1000;
    strcpy(resist[4].color, "yellow"); resist[4].value = 4; resist[4].times=10000;
    strcpy(resist[5].color, "green" ); resist[5].value = 5; resist[5].times=100000;
    strcpy(resist[6].color, "blue"  ); resist[6].value = 6; resist[6].times=1000000;
    strcpy(resist[7].color, "violet"); resist[7].value = 7; resist[7].times=10000000;
    strcpy(resist[8].color, "grey"  ); resist[8].value = 8; resist[8].times=100000000;
    strcpy(resist[9].color, "white" ); resist[9].value = 9; resist[9].times=1000000000;

    scanf("%s", input_1);
    scanf("%s", input_2);
    scanf("%s", input_3);

    for(int i=0; i<10; i++){
        if(strcmp(input_1, resist[i].color) == 0) {
            result = resist[i].value * 10;
            break;
        }
    }

    for(int i=0; i<10; i++){
        if(strcmp(input_2, resist[i].color) == 0) {
            result += resist[i].value;
            break;
        }
    }

    for(int i=0; i<10; i++){
        if(strcmp(input_3, resist[i].color) == 0) {
            result *= resist[i].times;
            break;
        }
    }

    printf("%ld\n", result);
}