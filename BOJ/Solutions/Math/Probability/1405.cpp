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
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;

int base = 14;
int n, dir[4];
double ans = 0;
bool arr[29][29];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
void dfs(int r, int c, double percentage, int depth){
    //cout<<depth<<" "<<r<<" "<<c << " "<<percentage<<endl;
    if(!arr[r+base][c+base]){
        if(depth==n){
            ans+=percentage;
        }
        else{
            arr[r+base][c+base] = true;
            for (int i = 0; i < 4; i++)
            {
                dfs(r+dr[i], c+dc[i], percentage/100*dir[i], depth+1);   
            }
            arr[r+base][c+base] = false;
        }
    }
}
int main() {
    FAST
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        cin >> dir[i];
    }
    dfs(0,0,1,0);
    cout<<fixed;
    cout<<setprecision(14);
    cout<<ans<<endl;
}