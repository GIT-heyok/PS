#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

int main(void) {
    FAST
    string s;
    while (cin >> s) {
        if(s=="0")break;
        int l = 0, r = s.length() - 1;
        bool chk = true;
        while (l <= r) {
            if (s[l++] != s[r--])chk = false;
        }
        if(chk)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
