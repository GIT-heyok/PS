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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0;
    int twos = 0;
    ll ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i]=='2'){
            if(ones+(twos+1)*2<=n){
                twos++;
            }
        }
        else{
            if(ones+twos*2==n){
                if(twos>0){
                    twos--;
                    ones++;
                }
            }
            else{
                ones++;
            }
        }
        ans+=ones+twos;
    }

    cout<<ans<<endl;
}
