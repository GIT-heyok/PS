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

int n;
ll arr[MAX];
ll subSum[MAX];
ll getBiggest(int s, int e){
	if(s==e){
		return arr[s]*arr[s];
	}
	else{
		ll ans = 0;
		ans = max(getBiggest(s, (s+e)/2), ans);
		ans = max(getBiggest((s+e)/2+1, e), ans);
		int l = (s+e)/2, r = (s+e)/2+1;
		ll cur = min(arr[l], arr[r]);
		ans = max(ans,cur*(subSum[r+1]-subSum[l]));
		while(l>=s&&r<=e){
			ll nl = -1, nr=-1;
			if(l-1>=s){
				nl = arr[l-1];
			}
			if(r+1<=e){
				nr = arr[r+1];
			}
			if(nl==-1&&nl==nr){
				break;
			}
			if(nl>=nr){
				l--;
				cur = min(nl, cur);
			}
			else{
				r++;
				cur = min(nr, cur);
			}
			ans=max(ans,cur*(subSum[r+1]-subSum[l]));
		}	
		return ans;
	}
}
int main(){
	FAST
	cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
        subSum[0]=0;
        for (int i = 1; i <= n; i++)
        {
            subSum[i] = subSum[i-1]+arr[i-1];
        }
        
		cout<<getBiggest(0,n-1)<<endl;
}



