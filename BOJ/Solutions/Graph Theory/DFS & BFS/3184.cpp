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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

bool chk[250][250];
char arr[250][250];
int n, m;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

pI dfs(int r, int c){
    if(chk[r][c]) return {0,0};
    chk[r][c] = true;
    if(arr[r][c]=='#') return {0,0};
    pI counter = {0,0};
    if(arr[r][c]=='v')counter.first++;
    if(arr[r][c]=='o')counter.second++;
    
    for (int i = 0; i < 4; i++)
    {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&!chk[nr][nc]){
            pI temp = dfs(nr, nc);
            counter.first+=temp.first;
            counter.second+=temp.second;
        }
    }
    return counter;
    
}
int main()
{
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
            chk[i][j] = false;
        }
        
    }

    int wolves = 0, sheep = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pI temp = dfs(i, j);
            if(temp.first>=temp.second)wolves+=temp.first;
            else sheep+=temp.second;
        }
    }
    cout<<sheep<<" "<<wolves<<endl;
    
    
}