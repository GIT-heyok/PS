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
const int inf = 1e6;
const ll MOD = 10007;

string str;
int memo[MAX][MAX];
int dp(int s, int e){
    if(memo[s][e]!=-1)return memo[s][e];
    if(e-s<1)return 0;
    else if(e-s==1){
        if(str[s]=='a'&&str[e]=='t'){
            return 2;
        }
        else if(str[s]=='g'&&str[e]=='c'){
            return 2;
        }
        else return 0;
    }
    int& ans = memo[s][e];
    ans = 0;
    if(str[s]=='a'&&str[e]=='t'){
        ans = 2+dp(s+1, e-1);
    }
    else if(str[s]=='g'&&str[e]=='c'){
        ans = 2+dp(s+1, e-1);
    }
    else{
        ans = dp(s+1,e-1);
    }
    for (int i = s; i <e; i++)
    {
        ans = max(ans, dp(s, i)+dp(i+1,e));
    }
    return ans;
    
}
int main()
{
    FAST;
    cin >> str;
    int sz = str.length();
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout<<dp(0,sz-1)<<endl;
     
}