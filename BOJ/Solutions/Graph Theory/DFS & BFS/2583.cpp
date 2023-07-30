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

bool arr[MAX][MAX];
bool chk[MAX][MAX];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int r, c;

int dfs(bool base, int r1, int c1){
    if(r1>=0&&r1<r&&c1>=0&&c1<c&&!chk[r1][c1]&&base==arr[r1][c1]){
        int curSum = 1;
        chk[r1][c1] = true;
        for (int i = 0; i < 4; i++)
        {
            curSum+=dfs(base, r1+dr[i], c1+dc[i]);
        }
        return curSum;
    }
    return 0;
}

int main()
{
    FAST
    cin >> r >> c;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        for (int i = r1; i < r2; i++)
        {
            for (int j = c1; j < c2; j++)
            {
                arr[i][j] = true;
            }
            
        }
    }
    vector<int> ans;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int temp = dfs(arr[i][j], i, j);
            if(temp&&!arr[i][j])ans.push_back(temp);
        }
        
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    
}