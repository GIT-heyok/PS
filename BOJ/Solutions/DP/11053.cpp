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
const int MAX = 1001;
int n;
int arr[MAX];
int memo[MAX];
//dp[i] =    
int dp(int index){
	if(index==0)return 1;
	if(memo[index]!=1)
		return memo[index];
	int& temp = memo[index];
	for (int i = 0; i < index; i++)
	{
		if(arr[i]<arr[index]){
			temp = max(dp(i)+1, temp);
		}
	}
	return temp;
}
int main()
{
    FAST
	// freopen("input.txt", "r", stdin);
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		memo[i] = 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(dp(i), ans);
	}
	
	cout<<ans<<endl;
		
}
    


