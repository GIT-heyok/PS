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
const ll INF = 1e12;
const int inf = 1234567890;

int arr[MAX];
int subSum[MAX];
int memo[MAX][MAX];

int dp(int a, int b){
	if(a==b)return 0;
	if(memo[a][b]!=inf)
		return memo[a][b];
	int& temp = memo[a][b];
	//joint at a
	for (int i = a; i < b; i++)
	{
		temp = min(dp(a,i)+dp(i+1, b)+subSum[b]-subSum[a-1], temp);
	}
	return temp;
}

int main()
{
    FAST
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		subSum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			subSum[i] = subSum[i-1]+arr[i];
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				memo[i][j] = inf;
			}
		}
		
		cout<<dp(1, n)<<endl;
		

		
		
	}
	
}

    


