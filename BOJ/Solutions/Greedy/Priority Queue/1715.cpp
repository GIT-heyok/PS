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
binary searchable
*/
int main()
{
    int n;
    cin >> n;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        pq.push(-temp);
    }
    ll ans = 0;
    while(pq.size()>=2){
        ll f = pq.top();
        pq.pop();
        ll s = pq.top();
        pq.pop();
        ans+=-(f+s);
        pq.push(f+s);
    }
    cout<<ans<<endl;
    
}