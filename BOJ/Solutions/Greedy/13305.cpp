#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
/*
Idea: distance*the minimum cost of the oil till found.

*/

int main()
{
    FAST
    int n;
    cin >> n;
    ll arr[n-1];
    ll cost[n];
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    ll ans = 0;
    ll curMin = cost[0];
    for (int i = 0; i < n-1; i++)
    {
        curMin = min(curMin, cost[i]);
        ans+=arr[i]*curMin;
    }
    cout<<ans<<endl;
    
}