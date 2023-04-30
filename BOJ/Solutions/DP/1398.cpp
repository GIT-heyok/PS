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

//split the problems in 100's and precalculate memo[0]~memo[99]
int main()
{
	FAST
	int memo[100];
	for (int i = 0; i < 100; i++)
	{
		memo[i] = (i%10)+(i/10)%10; 
	}
	for (int i = 0; i <100; i++)
	{
		if(i-25>=0){
			memo[i] = min(memo[i-25]+1, memo[i]);
		}
		if(i-50>=0){
			memo[i] = min(memo[i-50]+2, memo[i]);
		}
		if(i-75>=0){
			memo[i] = min(memo[i-75]+3, memo[i]);
		}
	}
	int T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		int ans = 0;
		while(n>0){
			ans +=memo[n%100];
			n/=100;
		}
		cout<<ans<<endl;
	}
	
	
}