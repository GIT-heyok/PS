#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;

int alphabet[26];

int main(void) {
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int cnt = 0;
        bool chk = true;
        for (int j = 0; j < s.length(); ++j) {
            if(s[j]=='('){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt<0)chk = false;
        }
        if(chk&&cnt==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
