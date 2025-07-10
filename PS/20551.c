#include <stdio.h>
#include <stdlib.h>

#define SIZE 200000

#define FALSE 0
#define TRUE  1

int comp(const void *a, const void *b){
    if(*(int*)a < *(int*)b)
        return -1;
    else if((int)a == (int)b)
        return 0;
    else
        return +1;
}

int main(){
    int n, m;
    int a[SIZE];
    int query[SIZE];
    int answer[SIZE];

    // 1. 입력 처리
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=0; i<m; i++)
        scanf("%d", &query[i]);

    // 2. 정렬
    qsort(a, n, sizeof(int), comp);

    // 3. 질의처리
    for(int i=0; i<m; i++){

        int left  = 0;
        int right = n-1;
        int mid;

        int flag = FALSE;

        while(left <= right){

            mid = (left + right) / 2;

            if (a[mid] >= query[i]){
                answer[i] = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;

            // 정답 발견
            if(a[mid] == query[i]){
                flag = TRUE;
            }
        }

        // 정답을 발견하지 못한 경우
        if(!flag)
            answer[i] = -1;
    }

    for(int i=0; i<m; i++)
        printf("%d\n", answer[i]);
}

// Test Case II

// 배열
// 2 3 3 3 4 4 5 9
// 0 1 2 3 4 5 6 7

// 질문
// 3 10 4 2

// 응답 
// 3 -1 5 0