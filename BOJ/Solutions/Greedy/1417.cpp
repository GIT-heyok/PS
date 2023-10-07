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
    int n;
    cin >> n;
    int cost;
    cin >> cost;
    priority_queue<int> pq;

    for (int i = 0; i < n-1; ++i) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int ans = 0;
    while(!pq.empty()&&pq.top()>=cost){
        cost++;
        ans++;
        int temp = pq.top();
        pq.pop();
        pq.push(temp-1);
    }
    cout<<ans<<endl;
}

