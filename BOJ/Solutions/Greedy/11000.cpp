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
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
int main()
{
    FAST
    
    int n;
    cin >> n;
    vector<pI> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second; 
    }
    sort(all(vec));
    
    priority_queue<int> pq;
    int sz = 0;
    int mx = 0;

    pq.push(vec[0].second);
    for (int i = 1; i < n; i++)
    {
        pq.push(-vec[i].second);

        if(-pq.top()<=vec[i].first){
            pq.pop();
        }
    }
    cout<<pq.size()<<endl;
    
}