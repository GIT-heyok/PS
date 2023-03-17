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
const int MAX = 1501;
const ll INF = 1e9;
int R, C;
int cur[MAX][MAX], nxt[MAX][MAX];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool visited[MAX][MAX];
int parent[MAX*MAX];

int find(int a){
    if(parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a>b){
        swap(a, b);
    }
    parent[b] = a;
}

void dfsIce(int r, int c){
    // cout<<r<<" "<<c<<" "<<cur[r][c]<<endl;
    if(visited[r][c])return;
    visited[r][c] = true;
    if(cur[r][c]=='.'||cur[r][c] == 'L'){
        nxt[r][c] = cur[r][c];
        for (int i = 0; i < 4; i++)
        {
            int nxr = r+dr[i], nxc = c+dc[i];
            if(nxr<R&&nxr>=0&&nxc<C&&nxc>=0){
                dfsIce(nxr, nxc);
            }
        }
    }
    else{
        nxt[r][c] = '.';   
    }
}

bool dfsSwan(int r, int c){
    // cout<<r<<" "<<c<<endl;
    if(visited[r][c])return false;
    visited[r][c] = true;
    bool stat = false;
    if(cur[r][c]=='L'){
        return true;
    }
    if(cur[r][c]=='.'){
    for (int i = 0; i < 4; i++)
    {
        int nxr = r+dr[i], nxc = c+dc[i];
        if(nxr<R&&nxr>=0&&nxc<C&&nxc>=0){
            if(dfsSwan(nxr, nxc))return true;
        }
    }
    }
    return false;
}

int main()
{
    FAST
    cin >> R >> C;
    int swR=0, swC = 0;
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            cur[i][j] = s[j];
            if(cur[i][j] == 'L'){
                swR = i, swC = j;
            }
        }
    }
        for (int ans = 0;; ans++)
        {
            bool chk = false;
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    visited[i][j] = false;
                }
            }
            visited[swR][swC] = true;
            for (int i = 0; i < 4; i++)
            {
                int nxR = swR+dr[i], nxC = swC+dc[i];
                if(nxR<R&&nxR>=0&&nxC<C&&nxC>=0){
                    chk|=dfsSwan(nxR, nxC);
                }
            }
            
            if(chk){
                cout<<ans<<endl;
                break;
            }
            
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    visited[i][j] = false;
                }
            }

            
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if(cur[i][j]=='.'||cur[i][j]=='L')
                    dfsIce(i, j);
                    else{
                        if(nxt[i][j]!='.'&&nxt[i][j]!='L'){
                            nxt[i][j] = 'X';
                        }
                    }
                }
                
            }
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    visited[i][j] = false;
                    cur[i][j] = nxt[i][j];
                }
            }

            // cout<<ans<<endl;
            // for (int i = 0; i < R; i++)
            // {
            //     for (int j = 0; j < C; j++)
            //     {
            //         cout<<(char)cur[i][j];
            //     }
            //     cout<<endl;
                
            // }
            // cout<<endl;
            
        }
        
    }
    

