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
const int MAX = 51;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;

vector<int> tree[MAX];
int memo[MAX];


int dp(int prev, int cur){
    int& ret = memo[cur];
    if(ret!=-1)return ret;
    ret = 0;
    vector<int> vec;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if(next!=prev)vec.push_back(dp(cur, next));
    }
    sort(all(vec));
    for (int i = 0; i < vec.size(); i++)
    {
        ret = max(ret,vec[i]+(int)vec.size()-i);   
    }
    return ret;
    
}

int main()
{
    FAST 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(i==0)continue;
        tree[a].push_back(i);
    }
    fill(memo, memo+n, -1);
    cout<<dp(0,0)<<endl;    
}
