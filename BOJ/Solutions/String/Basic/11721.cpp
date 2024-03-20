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
    int idx = 0;
    while(idx<s.length()){
        cout<<s[idx++];
        if(idx%10==0)cout<<endl;
    }
}
