#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

ll cnt[31];
int main(void) {
    FAST
    ll n, k, d;
    cin >> n >> k >> d;
    vector<pair<ll,ll>> vec(n);
    vector<ll> arr[n];
    for (int i = 0; i < n; ++i) {
        ll m,dd;
        cin >> m >> dd;
        vec[i] = {dd,i};
        for (int j = 0; j < m; ++j) {
            ll temp;
            cin >> temp;
//            cout<<temp<<endl;
            arr[i].push_back(temp);
        }
    }
    sort(vec.begin(), vec.end());

    ll start = 0;
    ll startD = vec[start].first;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        while(vec[i].first-startD>d){
            for (int j = 0; j < arr[vec[start].second].size(); ++j) {
                int cur = arr[vec[start].second][j];
//                cout<<"-"<<cur<<" ";
                cnt[cur]--;
            }
            start++;
            startD = vec[start].first;
        }
//        cout<<endl;
        for (int j = 0; j < arr[vec[i].second].size(); ++j) {
            int cur = arr[vec[i].second][j];
//            cout<<vec[i].second<<" +"<<cur<<" ";
            cnt[cur]++;
        }
//        cout<<endl;
        ll tmp = (ll)i-start+1;
        ll allKnow =0 ;
        ll oneKnow =0;
        for (int j = 1; j <= k; ++j) {
//            cout<<cnt[j]<<" ";
            if(cnt[j]>0)oneKnow++;
            if(cnt[j]==tmp)allKnow++;
        }
//        cout<<endl;
//        cout<<tmp<<" "<<allKnow<<" "<<oneKnow<<endl;
        ans = max(ans, (oneKnow-allKnow)*tmp);
    }
    cout<<ans<<endl;
}
