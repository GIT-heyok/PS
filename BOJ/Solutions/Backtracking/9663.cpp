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
const int MAX = 501;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
bool col[15], dr[30], dl[30];
int N;
ll cnt = 0;

//N-Queen

void dfs(int r, int c){
    if(r==N-1){cnt++;return;}
    for (int i = 0; i < N; i++)
    {
        if(!col[i]&&!dr[r+1+i]&&!dl[r-i+N]){
            col[i]=true;
            dr[r+1+i]=true;
            dl[r-i+N]=true;
            dfs(r+1, i);
            col[i]=false;
            dr[r+1+i]=false;
            dl[r-i+N]=false;
        }
    }
     

}
int main()
{
    FAST 
    cin >> N;
    memset(col, false, sizeof(col));
    memset(dr, false, sizeof(dr));
    memset(dl, false, sizeof(dl));
    dfs(-1,0);
    cout<<cnt<<endl;
    
}
