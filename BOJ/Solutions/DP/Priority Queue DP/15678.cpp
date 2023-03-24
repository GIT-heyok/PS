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
	int n, d;
	cin >> n >> d;
	vll arr(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	priority_queue<pLL> q;
	vll dp(n+1, -INF);
	q.push({0,0});
	for (int i = 1; i <= n; i++)
	{
		ll cur = 0;
		if(!q.empty()){
			// cout<<i<<" : "<<q.top().first<<" "<<q.top().second<<endl;
			if(arr[i]>=0){
				while(!q.empty()&&q.top().second<i-d){
					// cout<<"!"<<q.top().first<<" "<<q.top().second<<endl;
					q.pop();
				}
				
				ll sz = q.top().first;
				dp[i] = max(arr[i],arr[i]+sz);
				while(!q.empty()){
					q.pop();
				}
				q.push({dp[i],i});
			}
			else{
				while(!q.empty()&&q.top().second<i-d){
					// cout<<"!"<<q.top().first<<" "<<q.top().second<<endl;
					q.pop();
				}
				dp[i] = arr[i];
				if(!q.empty()){
					dp[i] = max(dp[i], q.top().first+arr[i]);
				}
				q.push({dp[i], i});
			}
		}
		// cout<<dp[i]<<" ";
	}
	ll ans = -INF;
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	
	cout<<ans<<endl;

	
	
}


