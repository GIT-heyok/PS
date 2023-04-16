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

ll memo[47];
ll fibonacci(int n){
    memo[1]=1;
    memo[2]=1;
    for (int i = 3; i <= n; i++)
    {
        memo[i] = memo[i-1]+memo[i-2];
    }
    return memo[n];
    
}


int main(){
    FAST 
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout<<fibonacci(n+1)<<endl;
    }
    
} 
