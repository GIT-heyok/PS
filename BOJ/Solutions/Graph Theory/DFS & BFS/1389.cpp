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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int main()
{
    FAST
    int n,m;
    cin >> n >> m;
    bool graph[n+1][n+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            graph[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int mxm = inf, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int bacon[n+1];
        for (int j = 0; j <= n; j++)
        {
            bacon[j] = inf;
        }
        bacon[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for (int j = 1; j <= n; j++)
            {
                if(graph[cur][j]&&bacon[j]>bacon[cur]+1){
                    bacon[j] = bacon[cur]+1;
                    q.push(j);
                }
            }
        }
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            temp+=bacon[j];
        }
        if(temp<mxm){
            mxm = temp;
            ans = i;
        }

        
    }
    
        cout<<ans<<endl;
}