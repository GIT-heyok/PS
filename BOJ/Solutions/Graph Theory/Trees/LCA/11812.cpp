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
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

//inspired by how segment trees are made
int main(){
	FAST
	ll n, k, q;
	cin >> n >> k >> q;
	while(q--){
		
		ll x, y;
		cin >> x >> y;
		x--,y--;
		if(k==1){
			cout<<abs(x-y)<<endl;
		}
		else{
			int ans = 0;
			while(x!=y){
				if(x<y)swap(x,y);
				x= (x-1)/k;
				ans++;
			}
			cout<<ans<<endl;
		}
	}

}

