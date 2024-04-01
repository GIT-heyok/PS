#include <algorithm>
#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {
    FAST
    int TC;
    cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        if(k==1){
            for (int i = 1; i <= n; ++i) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(k==n){
            for (int i = 0; i < n; ++i) {
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }

}

