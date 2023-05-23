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
const int MAX = 4000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

void setFile(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
int main()
{
    FAST
    setFile("hps");
    int n, k;
    cin >> n >> k;
    int picks[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s=="P"){
            picks[i] = 0;
        }
        else if(s=="H"){
            picks[i] = 1;
        }
        else{
            picks[i] = 2;
        }
    }

    int dp[n][k+1][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            for (int sss = 0; sss < 3; sss++)
            {
                dp[i][j][sss]=0;
            }
            
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        if(i==picks[0])dp[0][0][i]=1;
        else dp[0][0][i] = 0;
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            for (int aa = 0; aa < 3; aa++)
            {
                int& cur = dp[i+1][j][aa];
                if(aa==picks[i+1]){
                    cur=max(cur, dp[i][j][aa]+1);
                }   
                else{
                    cur = max(cur, dp[i][j][aa]);
                }
            }
            
            if(j>0){
                    int& cur = dp[i+1][j][picks[i+1]];
                    for (int bb = 0; bb < 3; bb++)
                    {
                        if(picks[i+1]==bb)continue;
                        cur = max(cur, dp[i][j-1][bb]+1);
                    }
            }

        }
        
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int a = 0; a < 3; a++)
        {
            //cout<<dp[n-1][i][a]<<" ";
            ans = max(ans, dp[n-1][i][a]);
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    
    
} 