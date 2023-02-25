#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>

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
const int MAX = 500001;
const int INF = 123456780;

int main()
{
    FAST
    int n, m;
    cin >> n >> m;
    ll arr[n+1][n+1];
    ll prefixSum[n+1][n+1];
    

for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            arr[i][j] = 0;
            prefixSum[i][j] = 0;
        }
    }

for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cin >> arr[i][j];       
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prefixSum[i][j+1] = prefixSum[i][j]+ arr[i][j+1];
        }
    }


    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            prefixSum[j+1][i] += prefixSum[j][i] ;
        }   
    }
    
    
    
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixSum[x2][y2] - prefixSum[x2][y1-1]-prefixSum[x1-1][y2] +prefixSum[x1-1][y1-1]<<endl; 
    }
        
       

}