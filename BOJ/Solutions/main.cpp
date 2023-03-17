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
const int MAX = 501;
int n;
ll arr[MAX][MAX];
ll memo[MAX][MAX];
ll dp(){
	for (int i =0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			memo[i+1][j] = max(memo[i+1][j], memo[i][j]+arr[i+1][j]);
			memo[i+1][j+1] = max(memo[i+1][j+1], memo[i][j]+arr[i+1][j+1]);
		}
		
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
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
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
			memo[i][j] = 0;
		}	
	}
	
	
	memo[0][0] = arr[0][0];
	cout<<dp()<<endl;
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		cout<<memo[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
	
}
    


