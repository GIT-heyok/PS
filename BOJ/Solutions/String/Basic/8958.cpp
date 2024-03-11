#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;


int main(void) {
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int ans = 0;
        int streak = 0;
        for (int j = 0; j < s.length(); ++j) {
            if(s[j]=='O'){
                ans += ++streak;
            }
            else{
                streak = 0;
            }
        }
        cout<<ans<<endl;
    }
}
