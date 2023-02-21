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
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 500001;
const int INF = 123456780;

vll vec, lv, rv;
void DFS(int s, int e, ll sum, vll& v){
    if(s>e){
        v.push_back(sum);
        return;
    }
    DFS(s+1,e,sum, v);
    DFS(s+1,e,sum+vec[s], v);
}

int main()
{
    FAST
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        ll k;
        cin >> k;
        vec.push_back(k);
    }
    DFS(0, n/2, 0, lv);
    DFS(n/2+1, n-1, 0, rv);
    sort(all(rv));
    ll ans = 0;
    
    for(int i=0; i<lv.size(); i++){
        ll temp = s-lv[i];
        ans+=upper_bound(all(rv), temp)-lower_bound(all(rv), temp);
    }
    if(s==0)ans--;
    cout<<ans<<endl;
    
}