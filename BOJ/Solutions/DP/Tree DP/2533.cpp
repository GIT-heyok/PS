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
const int inf = 1234567890;
const ll MOD = 1e9 + 7;

vector<int> tree[MAX];
int memo[MAX][2];
int dp(int prev, int cur, bool chk){
    int& ret = memo[cur][chk];
    if(ret!=-1){
        return ret;
    }
    if(chk){

        ret = 1;
        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i];
            if(next!=prev){
                ret+=min(dp(cur, next, false), dp(cur, next, true));
            }   
        }
        return ret;
    }
    else{
        ret = 0;
        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i];
            if(next!=prev){
                ret +=dp(cur, next,true);
            }       
        }
        return ret;
    }
}

int main()
{
    FAST 
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    fill(&memo[0][0], &memo[n+1][2], -1);
    cout<<min(dp(1,1,false),dp(1,1,true))<<endl;

    
}
