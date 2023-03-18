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
const int MAX = 10001;
const ll INF = 1e12;

/*dp(i) = max(dp(i-1)+arr[i], s[i]-s[i-m])
arr: array
s: subsum of array
*/

int main()
{
    FAST
	int n, m;
	cin >> n >> m;
	ll arr[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ll memo[n+1];
	for (int i = 0; i <= n; i++)
	{
		memo[i] = 0;
	}
	ll subSum[n+1];
	subSum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		subSum[i+1] = subSum[i]+arr[i+1];
	}
//	 for (int i = 0; i <= n; i++)
//	 {
//	 	cout<<subSum[i]<< " ";
//	 }
//	 cout<<endl;
	memo[m] = subSum[m];

	for (int i = m; i <= n; i++)
	{
		memo[i+1] = max(memo[i]+arr[i+1], subSum[i+1]-subSum[i+1-m]);
	}
//	for (int i = 0; i <= n; i++)
//	 {
//	 	cout<<memo[i]<< " ";
//	 }
//	 cout<<endl;
	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, memo[i]);
	}
	cout<<ans<<endl;
	

	
}

    


