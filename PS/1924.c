#include <stdio.h>

void calc_weekday(int month, int day);

int main(){
    int x,y;
    scanf("%d %d" , &x , &y);
    calc_weekday(x,y);
    return 0;
}

void calc_weekday(int month, int day){
    int i, sum = 0;
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
    for (i = 0; i < month; i++ ){
        sum +=days[i];
    }
    sum += day;
    
    if (sum % 7==0) printf("SUN");
    else if ( sum % 7 == 1) printf("MON");
    else if ( sum % 7 == 2) printf("TUE");
    else if ( sum % 7 == 3) printf("WED");
    else if ( sum % 7 == 4) printf("THU");
    else if ( sum % 7 == 5) printf("FRI");
    else if ( sum % 7 == 6) printf("SAT");
    
    
}