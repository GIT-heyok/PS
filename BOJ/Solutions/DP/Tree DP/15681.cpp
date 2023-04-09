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
const ll MOD = 1e9;
int n, r, q;
int memo[MAX];
bool visited[MAX];
vector<int> tree[MAX];
int dp(int k){

    visited[k] = true;
    if(memo[k]!=-1) return memo[k];
    int &temp = memo[k];
    temp = 1;
    for (int i = 0; i < tree[k].size(); i++)
    {
        if(!visited[tree[k][i]])
            temp += dp(tree[k][i]);
    }   
    return temp;
}
int main(){
    FAST
    cin >> n >> r >> q;
    for (int i = 1; i <= n; i++)
    {
        memo[i] = -1;
        visited[i] = false;    
    }

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a  >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dp(r);
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        cout<<memo[temp]<<endl;
    }
    
    
    
    
}