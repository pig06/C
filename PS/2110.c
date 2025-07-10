#include <stdio.h>
#include <stdlib.h>

#define SIZE 200000

int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
    /*
    if((int)a < (int)b)
        return -1;
    else if((int)a == (int)b)
        return 0;
    else
        return +1;
    */
}

int main(){
    int n; // 집의 개수
    int arr[SIZE]; // 집의 좌표
    int c; // 공유기의 개수

    // 1. 입력
    scanf("%d", &n);
    scanf("%d", &c);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // 2. 정렬
    qsort(arr,n, sizeof(arr[0]), comp);

    // 3. Binary Search
    int max_arr = arr[n-1] - arr[0];
    int min_arr = 1;
    int mid_arr;
    int answer = 1;

    int prev_r; // 바로 직전 설치한 공유기의 인덱스
    int next_r; // 직후 설치한 공유기의 인덱스
    int cnt_c;  // 현재 설치한 라우터의 개수

    while(min_arr <= max_arr) {

        prev_r = 0; 
        next_r = 1;
        cnt_c  = 1;

        mid_arr = (max_arr + min_arr) / 2;

        while( next_r < n ) {
            // 기준거리 불만족
            if ( arr[next_r] - arr[prev_r] < mid_arr ) 
                next_r++;
            // 기준거리 만족
            else {
                prev_r = next_r;
                next_r++;
                cnt_c++;
            }

            // 공유기 설치 완료 (과소평가)
            if(c == cnt_c) {
                min_arr = mid_arr + 1;
                answer = mid_arr;
                break;
            }
        }

        // 공유기 설치 실패 (과대평가)
        if(cnt_c < c) {
            max_arr = mid_arr - 1;
        }
    }

    // 4. 정답 출력
    printf("%d\n", answer);

    exit(EXIT_SUCCESS);
}
