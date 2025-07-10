#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

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
    int n; // 지방의 수
    int arr[SIZE]; // 각 지방에서 요구하는 예산금액
    int m; // 보유한 예산

    int MIN = 1000000000; // 각 지방에서 요구하는 예산의 최솟값
    int MAX = 1; // 각 지방에서 요구하는 예산의 최댓값
    int SUM = 0; // 각 지방에서 요구하는 예산의 합

    // 1. 입력 처리
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);

        SUM += arr[i];

        if(MIN > arr[i])
            MIN = arr[i];

        if(MAX < arr[i])
            MAX = arr[i];
    }

    scanf("%d", &m);

    // 1-1. 예외 처리
    if(SUM < m){
        printf("%d\n", MAX);
        exit(EXIT_SUCCESS);
    }

    // 2. 정렬
    qsort(arr,n, sizeof(arr[0]), comp);

    // 3. 탐색
    int max_arr = MAX;
    int min_arr = 0;
    int mid_arr = (max_arr+min_arr)/2;
    int answer = mid_arr;

    while(min_arr <= max_arr){

        // printf("min_arr: %d\n", min_arr);
        // printf("max_arr: %d\n\n", max_arr);

        int sum=0;
        // 3-1. 실제 할당한 예산값 계산
        for(int i=0; i<n; i++){
            if(arr[i] <= mid_arr)
                sum += arr[i];
            else
                sum += mid_arr;
        }

        // 과대평가한 경우
        if(sum > m){
            max_arr = mid_arr-1;
        }

        // 과소평가한 경우
        else if (sum < m){
            answer = mid_arr;
            min_arr = mid_arr+1;
        }

        // 정답인 경우 (sum == m)
        else{
            answer = mid_arr;
            break;
        }

        mid_arr = (max_arr + min_arr)/2;

    }


    // 4. 정답 출력
    printf("%d\n", answer);

    exit(EXIT_SUCCESS);
}