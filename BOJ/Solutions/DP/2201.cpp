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

/*
it's about finding pattern:
let fib(1)=1, fib(2)=2
fib(i) = fib(i-1)+fib(i-2)
kth pinary number's ith digit:
1 if k>=fib(i)
0 if k<fib(i)

k should be subtracted with fib(i) if the result is one.
*/
int main()
{
	FAST
	vector<ll> fib;
	fib.push_back(1);
	fib.push_back(1);
	int cur = 2;
	while(fib[cur-1]+fib[cur-2]<=1e18){
		fib.push_back(fib[cur-1]+fib[cur-2]);
		cur++;
	}

	int oneMax = 0;
	ll k;
	cin >> k;
	for (int i = 1; i <fib.size(); i++)
	{
		if(k>=fib[i])oneMax=i;
	}
	for (int i = oneMax; i >= 1; i--)
	{
		if(k>=fib[i]){
			cout<<"1";
			k-=fib[i];
		}
		else cout<<"0";
	}
	cout<<endl;
	
	
	
}