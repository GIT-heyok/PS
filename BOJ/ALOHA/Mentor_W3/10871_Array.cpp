#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    FAST
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t; // 임시 변수를 세팅
        if(t < x){ // 작다면
            cout << t << " "; // 출력 공백
        }
    }
    cout << endl;
}
