#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e6;

/*
jadu can be eaten when 2-> moved odd, 1-> moved even
memo[i][j] = max(memo[i-1][j-1]+((j)%2), memo[i-1][j]+(j+1)%2);
          
*/
int main(){
    FAST
    int n;
    cin>> n;

    vector<pI> conf(n+1);
    vector<pI> confSort(n+1);
    conf[0]={0,0};
    confSort[0]={0,0};
    for (int i = 1; i <= n; i++)
    {
        int s,e,w;
        cin >> s >> e >> w;
        conf[i].first=s;
        conf[i].second=w;
        confSort[i].first = e;
        confSort[i].second = i;
    }
    sort(all(confSort));
    int dp[n+1];
    fill(dp, dp+n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1];
        auto cur = conf[confSort[i].second];
        pI temp = {cur.first, 0};
        // cout<<cur.first<<":";
        int a = upper_bound(all(confSort),temp)-confSort.begin();
        a--;
        dp[i] = max(dp[i], dp[a]+conf[confSort[i].second].second);
        // cout<<dp[a]<<endl;
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout<<dp[n]<<endl;
    
    
    
    
    
    
    
}