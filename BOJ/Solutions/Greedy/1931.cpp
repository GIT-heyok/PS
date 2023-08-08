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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
int main()
{
    FAST
    
    int n;
    cin >> n;
    vector<pI> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(all(vec));
    ll startPos = INF;
    int ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        //cout<<startPos<<" "<<vec[i].first<<" "<<vec[i].second<<endl;
        if(vec[i].second<startPos){
            ans++;
            startPos = vec[i].first;
        }
    }
    cout<<ans<<endl;
    
    
}