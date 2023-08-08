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

int main()
{
    FAST
    int dr[8] = {1,2,2,1,-1,-2,-2,-1};
    int dc[8] = {-2,-1,1,2,2,1,-1,-2};
    int T;
    cin >> T;
    while(T--){
        int l;
        cin >> l;
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >>r2 >> c2;
        int path[l][l];
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
            {
                path[i][j] = inf;
            }
        }
        path[r1][c1] = 0;
        queue<pI> q;
        q.push({r1,c1});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0&&nr<l&&nc>=0&&nc<l&&path[nr][nc]>path[r][c]+1){
                    path[nr][nc] = path[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        cout<<path[r2][c2]<<endl;
        
    }
}