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
const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
ll modExp(ll a, ll b, ll m){
	if(b==0)return 1%m;
	ll temp = modExp(a,b/2,m);
	temp*=temp;
	temp%=m;
	if(b%2==1){
		return (temp*a)%m;
	}
	else{
		return temp;
	}
}
int main(){
	FAST
	ll a, b, m;
	cin >> a >>b >>m;
	cout<<modExp(a,b,m)<<endl;
}
