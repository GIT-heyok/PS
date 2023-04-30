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

const int MAX = 5001;
const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e9+7;

/*
Sort with regards to h, and 
dp[i+1] = max(dp[i], dp[ub-1]+price[i+1])
ub-1: means largest index which has height of h[i+1]-s 
*/
int main()
{
	FAST
	int n, s;
	cin >> n >> s;
	vector<pLL> paintings(n+1);
	paintings[0] = {-INF, -INF};
	for (int i = 1; i < n+1; i++)
	{
		cin >> paintings[i].first>>paintings[i].second;
	}
	ll memo[n+1];
	memo[0] = 0;
	sort(all(paintings));
	for (int i = 1; i <= n; i++)
	{
		pLL search = {paintings[i].first-s,INF};
		int idx = upper_bound(all(paintings), search)-paintings.begin();
		idx--;
		memo[i] = memo[i-1];
		if(idx>=0){
			memo[i] = max(memo[i], memo[idx]+paintings[i].second);
		}
	}
	// for (int i = 0; i <= n; i++)
	// {
	// 	cout<<memo[i]<<" ";
	// }
	
	cout<<memo[n]<<endl;
	
}