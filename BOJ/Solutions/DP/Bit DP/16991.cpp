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
double dist[MAX][MAX];
int n;
double memo[MAX][1<<MAX];
double getDist(pair<double, double> coord1, pair<double, double> coord2){
    double x = coord1.first-coord2.first;
    double y = coord1.second-coord2.second;
    return sqrt(x*x+y*y);
}

double dfs(int cur, int bit){
    if(bit==((1<<n)-1)){
        if(dist[cur][0]==0)return INF;
        return dist[cur][0];
    }
    double& temp = memo[cur][bit];
    if(temp!=-1)return temp;
    temp = INF;
    for (int i = 0; i < n; i++)
    {
        if(dist[cur][i]==0)continue;
        if(bit&(1<<i))continue;
        temp = min(temp, dist[cur][i]+dfs(i,bit+(1<<i)));
    }
    return temp;
    
}
int main()
{
    FAST 
    cin >> n;
    pair<double, double> coord[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        coord[i] = {a,b};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = getDist(coord[i], coord[j]);
        }
    }
    fill(&memo[0][0], &memo[15][1<<16], -1);
    cout<<setprecision(15)<<fixed;
    cout<<dfs(0,1)<<endl;
    

    
}
