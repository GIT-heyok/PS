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
const int INF = 1234567890;

int lisLen(int l, int r, vi& vec, bool rev=false){
    vi ans;
    if(rev){
        for (int i = l; i <= r; i++)
        {
            vec[i] *=-1;
        }
        
    }
    ans.push_back(vec[l]);
    for (int i = l+1; i <= r; i++)
    {
        if(vec[i]>ans[ans.size()-1]){
            ans.push_back(vec[i]);
        }
        else{
            *lower_bound(all(ans), vec[i]) = vec[i];
        }
    }
    if(rev){
        for (int i = l; i <= r; i++)
        {
            vec[i] *=-1;
        }
        
    }
    return ans.size();
}

int main()
{
    FAST
    int n;
    cin >> n;
    vi vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(lisLen(0,i,vec)+lisLen(i,n-1,vec,true)-1, ans);
    }
    cout<<ans<<endl;


    
    

    
}

