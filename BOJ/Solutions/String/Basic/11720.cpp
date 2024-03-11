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
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        sum += s[i]-'0';
    }
    cout<<sum<<endl;
}
