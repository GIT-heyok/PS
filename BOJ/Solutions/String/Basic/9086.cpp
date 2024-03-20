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
    int T;
    while(T--){
        string s;
        cin >> s;
        cout<<s[0]<<s[s.length()-1]<<endl;
    }
}
