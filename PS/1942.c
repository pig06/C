#include <stdio.h>
#include <stdlib.h>

#define TRUE  1;
#define FALSE 0;

typedef struct time{
    int hour;
    int minute;
    int second;
}time;

int equal_time(time t1, time t2){
    if(t1.second == t2.second){
        if(t1.minute == t2.minute){
            if(t1.hour == t2.hour)
                return TRUE;
        }
    }

    return FALSE;
}

time after_1s(time t){
    if(t.second < 59){
        t.second++;
    }
    else{
        t.second = 0;
        t.minute++;

        if(t.minute==60){
            t.minute=0;
            t.hour++;

            if(t.hour == 24)
            t.hour = 0;
        }
    }

    return t;
}

int time_to_int(time t){
    int int_time=0;

    int_time += t.second;
    int_time += t.minute * 100;
    int_time += t.hour   * 10000;

    return int_time;
}


int main(){
    time t1, t2;


    while(scanf("%d:%d:%d %d:%d:%d", &t1.hour, &t1.minute, &t1.second, &t2.hour, &t2.minute, &t2.second) != EOF){

        int answer_cnt=0;

        while(!equal_time(t1, t2)){

            // 시작시각이 3의 배수인가?
            if(time_to_int(t1) % 3 ==0)
                answer_cnt++;

            // 시작시각 1초 증가
            t1 = after_1s(t1);
        }

        printf("%d\n", answer_cnt);
    }

    exit(EXIT_SUCCESS);
}