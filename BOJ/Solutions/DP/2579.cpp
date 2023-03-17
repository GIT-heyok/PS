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
const int MAX = 301;
int n;
ll arr[MAX];
ll memo[MAX][2];
ll dp(){
	memo[0][0] = 0;
	memo[1][0] = arr[1];

	for (int i =1; i <= n; i++)
	{
		if(i>=2)
			memo[i][0] = max(memo[i-2][0]+arr[i],memo[i-2][1]+arr[i]);
		memo[i][1] = memo[i-1][0]+arr[i];
	}
	return max(memo[n][0], memo[n][1]);
}
int main()
{
    FAST
	cin >> n;	
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i <= MAX; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			memo[i][j] = 0;
		}
	}
	cout<<dp()<<endl;
	
}
    


