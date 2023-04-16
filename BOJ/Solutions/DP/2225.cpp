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
const ll MOD = 1e9;
int memo[201][201];
/*  n=0, k=1 -> base cases
    else:from 0 to n, n-=i, k-=1
*/
int dp(int n, int k){
     if(n==0)return 1;
     if(k==1)return 1;
     int& temp = memo[n][k];
     if(temp!=-1)return temp;
     temp = 0;
     for (int i = 0; i <= n; i++)
     {
        temp+=dp(n-i,k-1);
        temp%=MOD;
     }
     return temp;    
}
int main(){
    FAST 
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            memo[i][j] = -1;
        }
        
    }
    cout<<dp(n, k)<<endl;
    
}