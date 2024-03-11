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
    int T;
    cin >> T;
    while(T--){
        int it;
        cin >> it;
        string temp, ans;
        cin >> temp;
        for (int i = 0; i < temp.length(); ++i) {
            for (int j = 0; j < it; ++j) {
                ans+=temp[i];
            }
        }
        cout<<ans<<endl;
    }
}
