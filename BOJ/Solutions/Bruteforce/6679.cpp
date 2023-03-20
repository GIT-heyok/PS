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
const ll MOD = 1e9+7;

int getJari(int n, int mod){
	int ans = 0;
	while(n!=0){
		ans+=n%mod;
		n/=mod;
	}
	return ans;
}
bool isAmazing(int n){
	int a=getJari(n, 10), b = getJari(n, 12), c = getJari(n, 16);
	return a==b&&b==c;
}
int main(){
    FAST
	for (int i = 1000; i < 10000; i++)
	{
		if(isAmazing(i)){
			cout<<i<<endl;
		}
	}
	
}


