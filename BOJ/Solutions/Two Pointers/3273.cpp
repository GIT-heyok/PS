#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

ll cnt[2000001];
int main(){
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < 2000001; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        cnt[temp]++;
    }

    int x;
    cin >> x;

    ll ans = 0;
    int l=1, r=x-1;
    while(l<r){
        ans += cnt[l]*cnt[r];
        l++;
        r--;
    }

    if(l==r){
        ans+=cnt[l]*(cnt[l]-1)/2;
    }
    cout<<ans<<endl;
}
