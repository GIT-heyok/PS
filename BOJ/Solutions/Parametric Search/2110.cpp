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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
int n, c;
int router[MAX];

int parametricSearch(){
	ll l=1,r=inf;
	ll ans = 1;
	while(l<=r){
		ll mid = l+(r-l)/2;
		ll temp = 1;
		ll recent = router[0];
		for (int i = 1; i < n; i++)
		{
			if(router[i]-recent>=mid){
				temp++;
				recent = router[i];
			}
		}
		if(temp>=c){
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
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> router[i];
	}
	sort(router, router+n);
	cout<<parametricSearch()<<endl;
}

