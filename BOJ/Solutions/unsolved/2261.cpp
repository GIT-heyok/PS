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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int main()
{
    FAST 
    int n;
    cin >> n;
    vector<pLL> coord(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        coord[i] = {a,b};
    }
    sort(all(coord));
    ll curMax = INF;
    for (int i = 0; i < n; i++)
    {   
        ll x1 = coord[i].first;
        ll y1 = coord[i].second;
        for (int j = i+1; j < n; j++)
        {
            ll x2 = coord[j].first;
            ll y2 = coord[j].second;
            if((x2-x1)*(x2-x1)>=curMax)break;
            curMax = min(curMax, (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }   
    }
    cout<<curMax<<endl;
    
    
}
