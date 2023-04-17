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
const ll MOD = 1e6;

/*
two for loops by level and n         
*/
int main(){
    FAST
    int n,k;
    cin >> n >> k;
    int level[n];
    for (int i = 0; i < n; i++)
    {
        cin >> level[i];
    }
    int dp[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = 0;
    }
    
    
     for(int i = 0; i < n; i++){
            int mxm = 0;
            for(int j = 0; j < k; j++){
                if(i >= j){
                    if(level[i - j] > mxm) mxm = level[i - j];
                    dp[i + 1] = max(dp[i + 1], dp[i - j] + mxm * (j + 1));
                }
            }
        }

        for (int i = 0; i < n+1; i++)
        {
            cout<<dp[i]<<" ";
        }
        
    cout<<dp[n]<<endl;
    
    
    
}