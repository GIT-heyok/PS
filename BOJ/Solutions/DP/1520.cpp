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
const int INF = 1234567890;
int arr[500][500], memo[500][500];
bool visited[500][500];
int n, m;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,-1,1};
int dp(int r, int c){
    if(visited[r][c])return memo[r][c];
    visited[r][c] = true;
    int& temp = memo[r][c];
    if(r==0&&c==0) return temp = 1;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        int nxR = r+dr[i];
        int nxC = c+dc[i];
        if(nxR>=0&&nxR<n&&nxC>=0&&nxC<m){
            if(arr[r][c]<arr[nxR][nxC]){
                ans += dp(nxR, nxC);
            }
        }
       
    }
    return temp = ans;
    
    
}
int main()
{
    FAST
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memo[i][j] = 0;
            visited[i][j] = false;
            cin >> arr[i][j];
        }
        
    }
    cout<<dp(n-1, m-1)<<endl;
}

