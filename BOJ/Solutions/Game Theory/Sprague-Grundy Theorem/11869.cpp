#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main() {
    FAST
    int m;
    cin >> m;
    int grundy = 0;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        grundy^=temp;
    }
    if(grundy)cout<<"koosaga"<<endl;
    else cout<<"cubelover"<<endl;
}


