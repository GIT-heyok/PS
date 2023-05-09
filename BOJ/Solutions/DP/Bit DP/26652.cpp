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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const int INF = 123456780;

int n;
int memo[16][1<<16];
int arr[16][16];

//memo: cur is the last visited one! bit: all visited ones
int dfs(int cur, int bit){
    if(bit==((1<<n)-1)){
        if(arr[cur][0]==0)return INF;
        return arr[cur][0];
    }
    if(memo[cur][bit]!=-1)return memo[cur][bit];
    int& temp =memo[cur][bit];
    temp = INF;
    for (int i = 0; i < n; i++)
    {
        if(arr[cur][i]==0)continue;
        if(bit&(1<<i))continue;
        temp = min(temp, arr[cur][i]+dfs(i, bit+(1<<i)));
    }
    return temp;
    
}

int main()
{
    FAST
    /*
    first implement the going part
    */
   cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    fill(&memo[0][0], &memo[15][1<<16], -1);
    
    cout<<dfs(0,1)<<endl;
    
    
}
