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
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
int k;
ll ans = 0;
/*
dp returns the highest height among two subtrees (what are supposed to be filled with)
and in that function, it produces ans.
*/
ll tree[MAX];
ll dp(int cur){
    if(cur>=(1<<(k+1))-1)return 0;
    int n1 = tree[cur*2+1]+dp(cur*2+1);
    int n2 = tree[cur*2+2]+dp(cur*2+2);
    int ret = max(n1, n2);
    ans+=abs(n1-n2)+tree[cur*2+1]+tree[cur*2+2];
    return max(n1,n2);
}
int main()
{
    FAST 
    cin >> k;
    for (int i = 1; i < (1<<(k+1))-1; i++)
    {
        cin >> tree[i];
    }
    dp(0);

    cout<<ans<<endl;
    
}
