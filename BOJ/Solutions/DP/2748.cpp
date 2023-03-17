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
const int MAX = 91;
int n;
ll memo[MAX];
ll dp(int index){
	if(index==0)return 0;
	else if(index==1)return 1;
	if(memo[index]!=-1)
		return memo[index];
	ll& temp = memo[index];  
	return temp = dp(index-1)+dp(index-2);
}
int main()
{
    FAST
	cin >> n;	
	for (int i = 0; i < MAX; i++)
	{
		memo[i] = -1;
	}
	
	cout<<dp(n)<<endl;
}
    


