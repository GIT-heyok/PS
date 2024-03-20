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
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int l = 0;
        int r = s.length()-1;
        bool chk = true;

        while(l<=r){
            if(s[l++]!=s[r--]){
                chk = false;
                break;
            }
        }
        if(chk){
            cout<<0<<endl;
            continue;
        }
        l=0, r=s.length()-1;
        int cnt = 0;
        while(l<=r){
            if(s[l++]!=s[r--]){
                cnt++;
                l--;
            }
        }
        if(cnt==1){
            cout<<1<<endl;
            continue;
        }
        l=0, r=s.length()-1;
        cnt = 0;
        while(l<=r){
            if(s[l++]!=s[r--]){
                cnt++;
                r++;
            }
        }
        if(cnt==1){
            cout<<1<<endl;
            continue;
        }
        cout<<2<<endl;

    }
}
