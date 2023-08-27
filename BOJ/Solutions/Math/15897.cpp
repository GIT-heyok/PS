#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;

typedef long long ll;
int main() {
    FAST
    int n;
    cin >> n;
    ll ans = n;
    n--;
    ll counted = 0;
    ll num = 0;
    for (int i = 1; i <= n; i++)
    {
        ans+=n/i;
        counted++;
        if(counted>=n){
            break;
        }
        num++;
        ll temp = n/i-n/(i+1);
        counted+=temp;
        ans+=temp*num;
        if(counted>=n){
            break;
        }

    }
    cout<<ans<<endl;
    
}