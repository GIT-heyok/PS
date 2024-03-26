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
    bool chk[31]; // 출석부를 생성한다.
    for (int i = 1; i <= 30; ++i) { // 1번 부터 30번까지 출석부를 초기화 한다.
        chk[i] = true;
    }
    for (int i = 0; i < 28; ++i) {
        int t;
        cin >> t; // t번 학생이 불렸다.
        chk[t] = false; // 불린 학생에 false라고 표시해준다.
    }

    for (int i = 1; i <= 30; ++i) {
        if(chk[i] == true){ // i번 학생이 true라면 (불리지 않았다면)
            cout << i << endl; // 출력한다.
        }
    }
}
