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
int n;
int arr[MAX][2];
int memo[MAX][MAX];

int dp(int a, int b){
	if(a==b)return 0;
	if(memo[a][b]!=inf)
		return memo[a][b];
	int& temp = memo[a][b];
	//joint at a
	for (int i = a; i < b; i++)
	{
		temp = min(dp(a,i)+dp(i+1, b)+arr[a][0]*arr[i][1]*arr[b][1], temp);
	}
	return temp;
}

int main()
{
    FAST
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			memo[i][j] = inf;
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++){
//			cout<<dp(i,j)<<" ";
//		}
//		cout<<endl;
//	}
	
	cout<<dp(1, n)<<endl;
		

		
		
	}
	


    


