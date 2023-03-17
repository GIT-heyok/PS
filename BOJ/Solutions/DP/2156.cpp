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
int n;
ll arr[MAX];
ll memo[MAX][3];

ll dp(){
	for (int i = 0; i < n-1; i++){
		memo[i+1][0] = max(memo[i][0], max(memo[i][1], memo[i][2]));
		memo[i+1][1] = memo[i][0]+arr[i+1];
		memo[i+1][2] = memo[i][1]+arr[i+1];
	}
	ll ans = 0;
	for (int i = 0; i < 3; i++)
	{
		ans = max(ans, memo[n-1][i]);
	}
	return ans;
}

int main()
{
    FAST
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			memo[i][j] = 0;
		}
	}
	memo[0][1] = arr[0];
	cout<<dp()<<endl;
}
    


