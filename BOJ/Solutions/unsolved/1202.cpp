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
	int n, k;
	cin >> n >> k;
	priority_queue<pLL> gems;
	gems.push({-2ll, -2ll});
	for (int i = 0; i < n; i++)
	{
		ll weight, value;
		cin >> weight >> value;
		gems.push({weight, value});
	}
	// while(!gems.empty()){
	// 	cout<<gems.top().first<<" "<<gems.top().second<<endl;
	// 	gems.pop();
	// }	
	vector<ll> bags(k+1);
	for (int i = 0; i < k; i++)
	{
		cin >> bags[i];
	}
	bags[k] = -1;
	sort(all(bags));
	ll ans = 0;
	for (int i = k; i > 0; i--)
	{
		//consider the case where curbag==nextBag for all
		ll curBag = bags[i];
		ll nextBag = bags[i-1];
		ll curMax = -1;
		while(gems.top().first>nextBag){
			curMax = max(curMax, gems.top().second);
			gems.pop();
		}
		queue<pLL> q;
		while(gems.top())
	}
	
	
}


