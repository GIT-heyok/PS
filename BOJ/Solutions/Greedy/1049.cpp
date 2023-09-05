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
	vector<int> sixes(m), ones(m);
	for (int i = 0; i < m; i++)
	{
		cin >> sixes[i] >> ones[i];
	}
	sort(sixes.begin(), sixes.end());
	sort(ones.begin(),ones.end());
	int ans = 1<<29;
	ans = min(ans, (n+5)/6*sixes[0]); //overbuy with the cheapest 6's
	ans = min(ans, n*ones[0]); //buy with the cheapest ones
	ans = min(ans, n/6*sixes[0]+n%6*ones[0]); //consist it with ones and 6's
	cout<<ans<<endl;

	
} 