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
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
int main(){
	FAST
    vi arr(8);
    vi perm = {0,1,2,3,4,5,6,7};
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int cnt = 0;
    do{
        cnt++;
        bool chk = true;
        for (int i = 0; i < 8; i++)
        {
            // cout<<perm[i]<<" ";
            ll a = arr[perm[i]];
            ll b = arr[(perm[(i+1)%8])];
            ll c = arr[(perm[(i+2)%8])];
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(2*c*c*a*a<b*b*(c+a)*(c+a)){}
            else{
                chk = false;
                break;
            }
        }
        // cout<<endl;
        if(chk)ans++;
    }
    while(next_permutation(all(perm)));
    cout<<ans<<endl;   
}


