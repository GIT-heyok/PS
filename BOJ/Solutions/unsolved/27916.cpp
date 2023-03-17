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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 300001;
const ll INF = 1e12;
int n, m, q;
vi apart(MAX);
int memo[MAX];
int cnt = 0;
//dp(i) = true if the condition can be satisfied till i
//dp(i) = (0~i-m)k dp(0)|dp(1)|dp(2)|...|dp(k)
bool dp(int idx, ll k){
	// cnt++;
	if(memo[idx]==0) return false;
	if(memo[idx]==1) return true;
	cnt++;
	cout<<idx<<" "<<k<<endl;
	int& temp = memo[idx];
	for (int i = idx-m; i >=0; i--)
	{
			if(apart[idx]-apart[i+1]<=k){
				if(dp(i,k)){
					return temp = true;
				}
			}
			else{
				return temp = false;
			}
	}
	return temp = 0;
}
int lb()
{
    int mid;
 
    int low = 0;
    int high = 1e9+1;
 
    while (low < high) {
        mid = low + (high - low) / 2;
  		memo[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			memo[i] = -1;
		}      
		if (dp(n, mid)) {
            high = mid;
        }
 
        else {
            low = mid + 1;
        }
		cout<<cnt<<endl;
    }
       
    return low;
}
int main()
{
    FAST
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> apart[i];
	}
	int ans = lb();
	cout<<ans<<endl;
	for (int i = 0; i < q; i++)
	{
		int ss;
		cin >> ss;
		cout<<(ss>=ans);
	}
	cout<<endl;
		
		
}
    


