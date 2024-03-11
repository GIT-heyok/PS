#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
/*
 * 010 cannot be treated same as 100
 */
int main(){
    FAST
    int n, m;
    cin >> n >> m;
    map<string, int> mm;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mm[s]++;
    }
    int k;
    cin >> k;
    int ans = 0;
    for (auto it = mm.begin(); it !=mm.end() ; ++it) {
        string temp = it->first;
        int cnt = 0;
        for (int i = 0; i < temp.length(); ++i) {
            if(temp[i]=='0'){
                cnt++;
            }
        }
        if(cnt<=k&&k%2==cnt%2){
            ans = max(ans, it->second);
        }
    }
    cout<<ans<<endl;

}