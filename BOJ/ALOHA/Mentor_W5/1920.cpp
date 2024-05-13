#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n' // \n도 써줘야함.
// 1920 수 찾기
int main(void) {
    FAST // 빠른 입출력 구현 해 주어야 함.
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        // ub - lb를 하면 그 원소가 몇 개 존재 하는지 빠른 시간에 알 수 있다.
        int cnt = upper_bound(arr, arr+n, temp) - lower_bound(arr, arr+n, temp);
        if(cnt>0){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    cout<<endl;
}
