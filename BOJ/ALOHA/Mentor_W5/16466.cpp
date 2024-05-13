#include <bits/stdc++.h>

using namespace std;

// 16466 콘서트
int main(void) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    // 가지고 있는 티켓 하나씩 갱신
    int nxt = 1;
    for (int i = 0; i < n; ++i) {
        if(vec[i]==nxt){
            nxt++;
        }
    }
    cout<<nxt<<endl;
}
