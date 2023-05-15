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
//#define endl '\n'
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

vector<int> tree[MAX];

int memo[MAX][40];

void dp(int prev, int cur){
    for (int i = 0; i < 40; i++)
    {
        memo[cur][i]=i+1;
    }
    
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if(prev!=next){
            dp(cur, next);
            for (int j = 0; j < 40; j++)
            {
            int curr = inf;
                for (int k = 0; k < 40; k++)
                {
                    if(j==k)continue;
                    curr=min(curr,memo[next][k]);
                }
             memo[cur][j]+=curr;   
            }
            
        }
    }
}

//do as many colors as possible!
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
    dp(1,1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<memo[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    cout<<min(memo[1][0], min(memo[1][1], min(memo[1][2],memo[1][3])))<<endl;
    
    
}
