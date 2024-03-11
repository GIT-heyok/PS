#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        int idx1 = 0, idx2 = 0;
        long long ans = 0;
        for (int i = 0; i < s1.length() / 2; ++i) {
            while(s1[idx1]!='a'){
                idx1++;
            }
            while(s2[idx2]!='a'){
                idx2++;
            }
            ans += abs(idx1-idx2);
            idx1++;
            idx2++;
        }
        cout<<ans<<endl;
    }
}