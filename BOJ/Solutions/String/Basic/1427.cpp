#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
int cnt[10];
int main(void) {
    FAST
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        cnt[s[i]-'0']++;
    }
    for (int i = 9; i >= 0; --i) {
        while (cnt[i] > 0)
            cout << i, cnt[i]--;
    }
    cout<<endl;
}
