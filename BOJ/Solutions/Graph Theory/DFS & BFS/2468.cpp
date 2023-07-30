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
const int MAX = 100;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int arr[MAX][MAX];
int n;
bool chk[MAX][MAX];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

bool dfs(int base, int r, int c){
    if(r>=0&&r<n&&c>=0&&c<n&&!chk[r][c]&&arr[r][c]>base){
        chk[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            dfs(base, r+dr[i], c+dc[i]);
        }
        return true;
    }
    return false;
}
int main()
{
    FAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int base = 0; base < 100; base++)
    {
        int cnt = 0;
        for (int it1 = 0; it1 < n; it1++)
        {
            for (int it2 = 0; it2 < n; it2++)
            {
                chk[it1][it2] = false;
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dfs(base,i,j))cnt++;
            }
        }
        ans = max(cnt, ans);
        
    }
    cout<<ans<<endl;
    
}