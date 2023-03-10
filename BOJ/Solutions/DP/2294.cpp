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
const int INF = 1234567890;
int memo[10001];
bool visited[10001];
vi coins;

int dp(int coin){
    if(visited[coin]){
        // cout<<coin<<" "<<memo[coin]<<endl;
        return memo[coin];
    }
    visited[coin] = true;
    int& ans = memo[coin];
    for (int i = 0; i < coins.size(); i++)
    {
        if(coin-coins[i]>=0){
            ans = min(ans, 1+dp(coin-coins[i]));       
        }
    }
    return ans;
}
int main()
{
    FAST
    int n, k;
    cin >> n >> k;
    fill(memo, &memo[10001], INF);
    fill(visited, &visited[10001], false);
    memo[0] = 0;
    visited[0] = true;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
     
    if(dp(k)==INF){
        cout<<-1<<endl;   
    }
    else{

    cout<<dp(k)<<endl;
    }

}

