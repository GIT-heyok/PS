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
const int MAX = 2e9+1;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
using namespace std;
int n;
int cacheLen[501], cacheCnt[501], S[500];
int lis3(int start){
    int& ret = cacheLen[start+1];
    if(ret!=-1)return ret;
    ret = 1;
    for (int next = start+1; next < n; next++)
    {
        if(start==-1||S[start]<S[next])
            ret = max(ret, lis3(next)+1);
    }
    return ret;
}

int count(int start){
    if(lis3(start)==1)return 1;
    int& ret = cacheCnt[start+1];
    if(ret!=-1)return ret;
    ret = 0;
    for (int next = start+1; next < n; next++)
    {
        if((start==-1||S[start]<S[next])&&lis3(start)==lis3(next)+1)
            ret = min<ll>(MAX, (ll)ret+count(next));
    }
    return ret;
    
}

void reconstruct(int start, int skip, vector<int>& lis){
    if(start!=-1)lis.push_back(S[start]);

    vector<pI> followers;
    for (int next = start+1; next < n; next++)
    {
        if((start==-1||S[start]<S[next])&&lis3(start)==lis3(next)+1)
            followers.push_back({S[next], next});
    }
    sort(all(followers));
    for (int i = 0; i < followers.size(); i++)
    {
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt<=skip)
        skip-=cnt;
        else {
            reconstruct(idx, skip, lis);
            break;
        }
    }
    
    
}
int main()
{
    FAST
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    fill(cacheLen, cacheLen+n, -1);
    fill(cacheCnt, cacheCnt+n, -1);
    vector<int> ans;
    reconstruct(0, k-1, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    

}

