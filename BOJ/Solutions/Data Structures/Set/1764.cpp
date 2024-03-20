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
    set<string> notHear;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        notHear.insert(s);
    }
    vector<string> ans;

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if(notHear.find(s)!=notHear.end()){
            ans.push_back(s);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(string s: ans){
        cout<<s<<endl;
    }

}
