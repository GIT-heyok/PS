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
const int MAX = 10001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
int k, n;
int lan[MAX];
int parametricSearch(){
	ll l=1,r=(1ll<<31)-1;
	ll ans = 1;
	while(l<=r){
		ll mid = l+(r-l)/2;
		ll temp = 0;
		for (int i = 0; i < k; i++)
		{
			temp+=lan[i]/mid;
		}
		if(temp>=n){
			l = mid+1;
			ans = max(ans,mid);
		}
		else{
			r = mid-1;
		}
		
	}
	return ans;

}
int main(){
	FAST
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> lan[i];
	}
	cout<<parametricSearch()<<endl;
}
