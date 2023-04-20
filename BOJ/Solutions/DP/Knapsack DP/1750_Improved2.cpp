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
const ll MOD = 1e7+3;

/*
1. memo[MAX] = 0 (MAX=100001)
2. iterate through 1~MAX-1 and memo[gcd(i,s[i])]+=memo[i]
3. memo[s[i]]++
4. print memo[1]
5. using std::map<int, int> is more benficial cause it is
a sparse table wtf!
*/
int main()
{
    FAST;
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    
    map<int, int> memo;
    for (int i = 0; i < n; i++)
    {
        for (auto j: memo)
        {
            int& temp= memo[__gcd(j.first,s[i])];
            temp =(temp+j.second)%MOD;
        }
        memo[s[i]]++;
        memo[s[i]]%=MOD;
    }
    cout<<memo[1]<<endl;
}
