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
//difference was the key.
int main()
{
    FAST
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >>temp;
        vec.push_back(temp);
    }
    sort(all(vec));
    vector<int> diff;
    for (int i = 0; i < n-1; i++)
    {
        diff.push_back(vec[i+1]-vec[i]);
    }
    sort(all(diff));
    int aa = n-k;
    ll ans = 0;
    for (int i = 0; i < aa; i++)
    {
        ans+=diff[i];
    }
    cout<<ans<<endl;
    
    
    
}