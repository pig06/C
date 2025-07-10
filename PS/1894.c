#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int isSame(double x1, double y1, double x2, double y2){
    if(x1 == x2 && y1 == y2)
        return TRUE;
    else
        return FALSE;
}

int main(){
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;

    // 정답 좌표
    double x=0.0, y=0.0;

    while(TRUE){
        if(scanf("%lf", &x1) == EOF)
            exit(EXIT_SUCCESS);

        scanf("%lf", &y1);
        scanf("%lf", &x2);
        scanf("%lf", &y2);
        scanf("%lf", &x3);
        scanf("%lf", &y3);
        scanf("%lf", &x4);
        scanf("%lf", &y4);

        if ( isSame(x1, y1, x2, y2) ){
            x = x3 + x4 - x1;
            y = y3 + y4 - y1;
        }
        else if ( isSame(x1, y1, x3, y3) ) {
            x = x2 + x4 - x1;
            y = y2 + y4 - y1;
        }
        else if ( isSame(x1, y1, x4, y4) ) {
            x = x2 + x3 - x1;
            y = y2 + y3 - y1;
        }
        else if ( isSame(x2, y2, x3, y3) ) {
            x = x1 + x4 - x2;
            y = y1 + y4 - y2;
        }
        else if ( isSame(x3, y3, x4, y4) ) {
            x = x1 + x2 - x3;
            y = y1 + y2 - y3;
        }
        else if ( isSame(x2, y2, x4, y4) ) {
            x = x1 + x3 - x2;
            y = y1 + y3 - y2;
        }

        printf("%.3lf %.3lf\n", x, y);
    }
}
