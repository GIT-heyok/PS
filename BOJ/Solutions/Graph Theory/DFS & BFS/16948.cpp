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
vector<int> pi(1000001);
int main()
{
    FAST

    int dr[6] = {-2,-2,0,0,2,2};
    int dc[6] = {-1,1,-2,2,-1,1};
    int n;
    cin >> n;
    int moves[n][n];
    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            moves[i][j] = inf;
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    moves[r1][c1] = 0;
    queue<pI> q;
    q.push({r1, c1});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n&&moves[nr][nc]>moves[r][c]+1){
                moves[nr][nc] = moves[r][c]+1;
                q.push({nr, nc});
            }
        }
    }
    if(moves[r2][c2]>=inf){
        cout<<-1<<endl;
    }
    else{
        cout<<moves[r2][c2]<<endl;
    }
}