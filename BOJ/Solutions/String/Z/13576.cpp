#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

vector<int> createZ(string& s){
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for (int i = 1; i < n; ++i) {
        if(i < r){
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r = i+z[i];
        }
    }
    return z;
}

typedef long long ll;
int main(void) {
    FAST
    string s;
    cin >> s;
    vector<int> z = createZ(s);
    vector<int> arr = z;
    sort( arr.begin(), arr.end());
    vector<pair<int, int>> ans;
    for (int i = s.length()-1; i >= 0; --i) {

        if(i+z[i]==s.length()){
            ans.push_back({z[i], arr.end()- lower_bound(arr.begin(),arr.end(),z[i])});
        }
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
