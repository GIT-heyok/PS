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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;
/*
sort it by the alphabet with the largest digit value
and add the sum
*/
int main()
{
    int n;
    cin >> n;
    ll arr[26];
    fill(arr, arr+26,0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll digit = 1;
        for (int j = s.length()-1; j >=0 ; j--)
        {
            arr[s[j]-'A']+=digit;
            digit*=10;
        }
    }
    sort(arr, arr+26);
    ll ans = 0;
    ll multiplier = 9;
    for (int i = 25; i >= 0; i--,multiplier--)
    {
        ans += arr[i]*multiplier;
    }
    cout<<ans<<endl;
    
}