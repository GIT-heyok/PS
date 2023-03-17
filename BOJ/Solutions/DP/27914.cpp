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

int main()
{
    FAST
	ll n, k, q;
	cin >> n >> k >> q;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vll ans(n, 0);
	ll streak = 0;
	for (int i = 0; i < n; i++)
	{
		if(arr[i]!=k){
			streak++;
		}
		else{
			streak = 0;
		}
		ans[i] = streak;
	}
	for (int i = 0; i < n-1; i++)
	{
		ans[i+1]+= ans[i];
	}
	for (int i = 0; i < q; i++)
	{
		int s;
		cin >> s;
		cout<<ans[s-1]<<endl;
	}
	
		
}
    


