#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

//same problem as 1781.cpp
int main() {    
    FAST
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[i] = {a,b};
    }
    vec.push_back({0,0});
    sort(vec.begin(), vec.end());
    int current = vec[n].first;
    int ans = 0;
    priority_queue<int> pq;
    //auto f = [&](pair<int,int> a){cout<<a.first<<" "<<a.second<<endl;};
    for (int i = n; i >=0; i--)
    {
    //   f(vec[i]);
        while(current>vec[i].first&&!pq.empty()){
            ans+=pq.top();
            //cout<<pq.top()<<endl;
            pq.pop();
            current--;
        }
        current = vec[i].first;
        pq.push(vec[i].second);
    }
    cout<<ans<<endl;
}