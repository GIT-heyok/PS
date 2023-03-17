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
int n;
ll arr[MAX][3];
ll memo[MAX][3];

ll dp(){
	for (int i = 0; i < n-1; i++){
		memo[i+1][0] = min(memo[i][1]+arr[i+1][0], memo[i][2]+arr[i+1][0]);
		memo[i+1][1] = min(memo[i][0]+arr[i+1][1], memo[i][2]+arr[i+1][1]);
		memo[i+1][2] = min(memo[i][0]+arr[i+1][2], memo[i][1]+arr[i+1][2]);
	}
	ll ans = INF;
	for (int i = 0; i < 3; i++)
	{
		ans = min(ans, memo[n-1][i]);
	}
	return ans;
}

int main()
{
    FAST
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			memo[i][j] = INF;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		memo[0][i] = arr[0][i];
	}
	cout<<dp()<<endl;	
}
    


