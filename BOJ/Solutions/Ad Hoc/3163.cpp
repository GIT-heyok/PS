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
int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, l, k;
        cin >> n >> l >> k;
        vector<pI> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i].first >> vec[i].second;
        }
        vector<int> neg, pos;
        for (int i = 0; i < n; i++)
        {
            if(vec[i].second<0){
                neg.push_back(vec[i].first);
            }
        }
        for (int i = n-1; i>=0; i--)
        {
            if(vec[i].second>0)pos.push_back(l-vec[i].first);
        }
        for (int i = 0; i < neg.size(); i++)
        {
            vec[i].first = neg[i];
        }
        
        for (int i = 0; i < pos.size(); i++)
        {
            vec[i+neg.size()].first = pos[pos.size()-i-1];
        }
        sort(all(vec));
        
        
        cout<<vec[k-1].second<<endl;
        
        
        
    }
}