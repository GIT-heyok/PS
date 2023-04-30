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
#include <memory.h>

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
typedef pair<double, double> pD;

const int MAX = 5001;
const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e9+7;

const int N_MAX = 1000;
int n, m;
vector<int> dp(N_MAX, inf);
vector<int> names(N_MAX, 0);

int solution(int idx){
	if(dp[idx] < inf)
		return dp[idx];

	int remain = m - names[idx]; 

	for(int i=idx+1;i<=n && remain>=0;i++){
		if(i == n){
			dp[idx] = 0;
			break;
		}
		dp[idx] = min(dp[idx], remain * remain + solution(i)); //재귀 호출
		remain -= names[i] + 1; 
	}

	return dp[idx];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> names[i];

	dp[n - 1] = 0;

	cout << solution(0) << endl;

	return 0;
}