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
const int MAX = 300001;
const ll INF = 1e12;
const int inf = 1e9;
int n, m, q;
vi apart(MAX);
int memo[MAX];
bool dp(ll k)
{
    queue<int> q;
    q.push(0);
    for (int i = 1; i <= n; i++)
    {
        memo[i] = false;
        while(!q.empty()){
        
            int nxt = q.front();
            // cout<<i<<" "<<apart[i]<<" "<<nxt<<" "<<apart[nxt]<<endl;
            if(i-nxt+1<=m)break;
            if(i<m)break;
            if(apart[i]-apart[nxt+1]<=k){
                memo[i] = true;
                q.push(i);
                break;   
            }
            else{
            q.pop();
                continue;
            }
        }   
        // cout<<i<<" "<<memo[i]<<endl;
    }
    return memo[n];
    
}
int lb()
{
    int mid;

    int low = 0;
    int high = 1e9;
    int ans = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
    //  cout<<mid<<endl;   
        if (dp(mid))
        {
            ans = min(ans,mid);
            high = mid-1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main()
{
    FAST
            cin >>
        n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> apart[i];
    }
    apart[0]=inf;
    int ans = lb();
    // cout<<ans<<endl;
    for (int i = 0; i < q; i++)
    {
        int ss;
        cin >> ss;
        if(ss>=ans)cout<<1;
        else cout<<0;
    }
    cout << endl;
}
