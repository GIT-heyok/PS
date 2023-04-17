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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e9+7;

/*
dp(n,10,5)->third number: 0:0, 1:+1, 2:+2, 3:-1, 4:-2

1. base case: dp(0,0~9,0)=1, everything else:0
2. dp(i,0~9,1)=dp(i-1,-1,(0,3,4));
*/
int main(){
    FAST
    int n;
    cin >> n;
    ll memo[n][10][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                memo[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        memo[0][i][0]=1;
    }

    for (int i = 1; i < n; i++)
    {
        //1 case
        for (int j = 1; j < 10; j++)
        {
            memo[i][j][1]+=memo[i-1][j-1][0];
            memo[i][j][1]+=memo[i-1][j-1][3];
            memo[i][j][1]+=memo[i-1][j-1][4];
            memo[i][j][1]%=MOD;
        }

        //2 case
        for (int j = 1; j < 10; j++)
        {
            memo[i][j][2]+=memo[i-1][j-1][1];
            memo[i][j][2]%=MOD;
        }

                
        //3 case
        for (int j = 0; j < 9; j++)
        {
            memo[i][j][3]+=memo[i-1][j+1][0];
            memo[i][j][3]+=memo[i-1][j+1][1];
            memo[i][j][3]+=memo[i-1][j+1][2];
            memo[i][j][3]%=MOD;
        }
        
        //4 case
        for (int j = 0; j < 9; j++)
        {
            memo[i][j][4]+=memo[i-1][j+1][3];
            memo[i][j][4]%=MOD;
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ans += memo[n-1][i][j];
            ans%=MOD;
        }
        
    }
    cout<<ans<<endl;
       
    
}