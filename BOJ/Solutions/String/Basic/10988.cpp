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
    cin >> s;
    int l = 0, r = s.length() - 1;
    bool chk = true;
    while (l <= r) {
        if (s[l++] != s[r--])chk = false;
    }
    cout << chk << endl;
}
