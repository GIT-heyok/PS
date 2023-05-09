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
const int MAX = 16;
const double INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
int n;
int memo[MAX][1<<MAX];

vector<int> graph[MAX];
string words[MAX];
int dfs(int cur, int bit){
    if(cur==-1){
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(i, (1<<i)));
        }
        return ans;
    }
    int& temp = memo[cur][bit];
    if(temp!=-1)return temp;
    temp = words[cur].length();
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next=graph[cur][i];
        if(bit&(1<<next))continue;
        temp = max(temp, (int)words[cur].length()+dfs(next,bit+(1<<next)));
    }
    return temp;
    
}
int main()
{
    FAST 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    for (int i = 0; i < n; i++)
    {
        char iEnd = words[i][words[i].length()-1];
        for (int j = 0; j < n; j++)
        {
            if(i==j)continue;
            char jStart = words[j][0];
            if(iEnd==jStart){
                graph[i].push_back(j);
            }   
        }
    }
    fill(&memo[0][0], &memo[MAX-1][(1<<MAX)-1], -1);
    cout<<dfs(-1,0)<<endl;
    
    
}
