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
const int MAX = 101;
int n, m;
int mem[MAX];
int cost[MAX];
int memo[MAX][MAX*MAX];
int dp(){
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if(j-cost[i+1]>=0)
				memo[i+1][j] = max(memo[i+1][j],memo[i][j-cost[i+1]]+mem[i+1]);
			memo[i+1][j] = max(memo[i+1][j],memo[i][j]);
		}
	}
	
	for (int i = 0; i <= 10000; i++)
	{
		// cout<<memo[n-1][i]<<" ";
		if(memo[n-1][i]>=m){
			return i;
		}
	}
	return 0;
}
int main()
{
    FAST
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> mem[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			memo[i][j] = 0;
		}
	}
	memo[0][cost[0]] = mem[0];
	cout<<dp()<<endl;
}
    


