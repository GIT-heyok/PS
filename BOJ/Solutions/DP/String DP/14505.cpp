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

const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e7 + 3;

int dp[31][31];
string ss;
int solve(int s, int e){
    if(dp[s][e]!=-1)return dp[s][e];
    int& temp = dp[s][e]=solve(s,e-1)+solve(s+1,e);
    if(ss[s]==ss[e]){
        temp+=1;
    }
    else{
        temp-=solve(s+1,e-1);
    }return temp;
}
int main()
{
    FAST;
    cin >> ss;
    int sz = ss.length();
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if(i==j)dp[i][j]=1;
            else if(i<j)dp[i][j]=-1;
            else dp[i][j] = 0;
        }
    }

    cout<<solve(0,sz-1)<<endl;
    
}