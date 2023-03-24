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
	int n, m, dummy1, dummy2;
	cin >> n >> m >> dummy1 >> dummy2;
	vi top(n+1), bottom(m+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> top[i];
	}
	top[0] = -inf;
	for (int i = 1; i <= m; i++)
	{
		cin >> bottom[i];
	}
	bottom[0] = -inf; 

	sort(all(top));
	sort(all(bottom));
	ll ans = 0;
	vll bottomSmaller(n+1,0);
	vi hasEqual(n+1, 0);
	for (int i = 1; i <=n; i++)
	{
		bottomSmaller[i] = lower_bound(all(bottom),top[i])-bottom.begin()-1;
		bottomSmaller[i] += bottomSmaller[i-1];
		if(top[i]==*lower_bound(all(bottom), top[i])){
			hasEqual[i] = 1;
		}
		hasEqual[i] += hasEqual[i-1];
	}
	for (int i = 1; i <n ; i++)
	{
		ans += ((bottomSmaller[i]-bottomSmaller[i-1])%MOD)*((m*(n-i)-(bottomSmaller[n]-bottomSmaller[i]+(hasEqual[n]-hasEqual[i])))%MOD)%MOD;
	}

	vll topSmaller(m+1,0);
	vi hasEqualTOP(m+1, 0);
	for (int i = 1; i <=m; i++)
	{
		topSmaller[i] = lower_bound(all(top),bottom[i])-top.begin()-1;
		topSmaller[i] +=topSmaller[i-1];
		if(bottom[i]==*lower_bound(all(top), bottom[i])){
			hasEqualTOP[i] = 1;
		}
		hasEqualTOP[i] += hasEqualTOP[i-1];
	}
	// for (int i = 0; i < m+1; i++)
	// {
	// 	cout<<hasEqualTOP[i]<<" ";
	// }
	
	// cout<<endl;
	// cout<<ans<<endl;
	for (int i = 1; i <m ; i++)
	{
		// ll partA = topSmaller[i]-topSmaller[i-1];
		// ll partB = n*(m-i)-(topSmaller[m]-topSmaller[i]-(hasEqualTOP[m]-hasEqualTOP[i]));
		// cout<<partA<<" "<<partB<<endl;
		ans += ((topSmaller[i]-topSmaller[i-1])%MOD)*((n*(m-i)-(topSmaller[m]-topSmaller[i]+(hasEqualTOP[m]-hasEqualTOP[i])))%MOD)%MOD;

	}
	cout<<ans<<endl;



	
	
	
}


