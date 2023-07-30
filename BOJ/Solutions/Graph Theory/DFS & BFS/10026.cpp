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

int n;
char arr[MAX][MAX];
bool chk[MAX][MAX];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

void dfs(char base, int r, int c){
    if(r>=0&&r<n&&c>=0&&c<n&&!chk[r][c]&&arr[r][c]==base){
        chk[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            dfs(base, r+dr[i],c+dc[i]);
        }
    }
}

int main()
{
    FAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j];
        }
    }

    int ansPrev = 0, ansPost = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!chk[i][j]){
                ansPrev++;
                dfs(arr[i][j], i,j);
            }
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chk[i][j] = false;
            if(arr[i][j]=='R')arr[i][j] = 'G';
        }   
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(!chk[i][j]){
                ansPost++;
                dfs(arr[i][j], i,j);
            }
        }
        
    }
    cout<<ansPrev<<" "<<ansPost<<endl;

    
}