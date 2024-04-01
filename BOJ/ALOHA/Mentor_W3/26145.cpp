#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
// 26145 출제비 재분배
int main()
{
    FAST
    int n, m;
    cin >> n >> m;
    int arr[n+m+1]; // i~n번째: 출제자의 돈, n+1~n+m번째: 검수자의 돈 이것도 넉넉히 잡는다.
    for (int i = 1; i <= n+m; ++i) {
        arr[i] = 0; // 배열을 초기화 해준다.
    }
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i]; // 출제자의 돈을 설정한다.
    }
    for (int i = 1; i <= n; ++i) { // i번째 줄에서는 i번째 출제자의 돈이 빠져나간다.
        for (int j = 1; j <= n+m; ++j) {
            int t; // 입력된 숫자이다.
            cin >> t;
            arr[i] -= t; // 출제자의 돈을 빼서
            arr[j] += t; // 누군가에게 돈을 준다.
        }
    }

    for (int i = 1; i <= n+m; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
