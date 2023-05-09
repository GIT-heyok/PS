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

const int MAX = 101;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;

ll memo[MAX][10][1<<10];
int n;
ll dp(){
    for (int i = 1; i < 10; i++)
    {
        memo[0][i][1<<i] = 1;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < (1<<10); k++)
            {
                if(k&(1<<j)){
                    if(j-1>=0){
                        memo[i+1][j-1][k|(1<<(j-1))]+=memo[i][j][k];
                        memo[i+1][j-1][k|(1<<(j-1))]%=MOD; 
                    }
                    if(j+1<10){
                        memo[i+1][j+1][k|(1<<(j+1))]+=memo[i][j][k];
                        memo[i+1][j+1][k|(1<<(j+1))]%=MOD; 
                    }
                }
               
            }
            
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans+=memo[n-1][i][(1<<10)-1];   
        ans%=MOD;
    }
    return ans;
    
    
    
}
int main(){
	FAST
    cin >> n;
    fill(&memo[0][0][0], &memo[MAX-1][9][1<<10], 0ll);
    cout<<dp()<<endl;
}


