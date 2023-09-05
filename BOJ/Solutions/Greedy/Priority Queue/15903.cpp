#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}
	for (int i = 0; i < m; i++)
	{
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		pq.push(a+b);
		pq.push(a+b);
	}
	ll ans = 0;
	while(!pq.empty()){
		ans+=pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
	
	
}