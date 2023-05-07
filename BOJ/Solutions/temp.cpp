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
const int MAX = 2e9+1;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int main()
{
    FAST
    priority_queue<pI> q;
    int n, m;
    cin >> n >> m;
    m*=2;
    m-=1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        while (!q.empty())
        {
            int nextVal = q.top().first;
            int nextIdx = q.top().second;
            if(nextIdx<=i-m||nextVal<=arr[i]){
                q.pop();    
            }
            else{
                break;   
            }
        }
        
        q.push({arr[i], i});
        // cout<<q.front().first<<" "<<q.front().second<<endl;
        ans[i] = q.top().first;
    }
    for (int i = m-1; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    
    
}

