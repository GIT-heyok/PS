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

int main(){
    FAST
    int n, w, p;
    cin >> n >> w >>  p;
    int arr[n+1][n+1];
    int dist[n+1][n+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            arr[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < w; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        arr[a][b] = w;
        arr[b][a] = w;
    }
    for (int i = 1; i <= n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==j)dist[i][j]=0;
            else if(arr[i][j])dist[i][j] = arr[i][j];
            else dist[i][j] = inf;
        }
        
    }
    for (int k = 1; k <=n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
            
        }
        
    }
    
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        cout<<dist[a][b]<<endl;
    }
    
    

    
}