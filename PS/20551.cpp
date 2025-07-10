#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 200000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int a[SIZE];
    int query[SIZE];
    int answer[SIZE];

    // 1. 입력 처리
    cin >> n >> m;

    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<m; i++)
        cin >> query[i];

    // 2. 정렬
    sort(a, a+n);

    // 3. 질의처리
    for(int i=0; i<m; i++){
        answer[i] = lower_bound(a, a+n, query[i]) - a;

        if(answer[i] == n || a[answer[i]] != query[i])
            answer[i] = -1;
    }

    for(int i=0; i<m; i++)
        cout << answer[i] << '\n';
}