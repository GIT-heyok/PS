#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main(){
    FAST
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    pair<int, int> top = vec[0], bottom = vec[0];
    for (int i = 1; i < n; ++i) {
        ans = max(ans, abs(top.first-vec[i].first)+abs(top.second-vec[i].second));
        ans = max(ans, abs(bottom.first-vec[i].first)+abs(bottom.second-vec[i].second));
        if(vec[i].second-top.second>vec[i].first-top.first){
            top = vec[i];
        }

        if(bottom.second-vec[i].second>vec[i].first-bottom.first){
            bottom = vec[i];
        }
    }
    cout<<ans<<endl;
}