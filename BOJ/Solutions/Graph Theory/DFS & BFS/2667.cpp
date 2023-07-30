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
const int MAX = 16;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

bool arr[50][50];
bool chk[50][50];
int r, c;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int dfs(int r1, int c1){
    if(r1>=0&&r1<r&&c1>=0&&c1<c&&!chk[r1][c1]&&arr[r1][c1]){
        int curSum = 1;
        chk[r1][c1] = 1;
        for (int i = 0; i < 4; i++)
        {
            curSum+=dfs(r1+dr[i],c1+dc[i]);
        }
        return curSum;
    }

    return 0;
}
int main()
{
    FAST
    int T = 1;
    while(T--){
        cin >> r;
        c = r;
        for (int i = 0; i < r; i++){
            string s;
            cin >> s;
            for (int j = 0; j < c; j++){
                chk[i][j] = 0;
                arr[i][j] = s[j]-'0'; 
            }
        }
        vector<int> ans;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int temp = dfs(i,j);
                if(temp>0)
                    ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for (auto i : ans)
        {
            cout<<i<<endl;
        }
        

    }
}