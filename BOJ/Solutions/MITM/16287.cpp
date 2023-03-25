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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 400001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

vector<int> ww(MAX, 0);

int main(){
	FAST
	int w, n;
	cin >> w >> n;
	vi arr(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(all(arr));
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			ww[arr[i]+arr[j]] = max(ww[arr[i]+arr[j]],i);			
		}
		
	}

	bool chk = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if(arr[i]+arr[j]>w/2){
				break;
			}
			if(w-arr[i]-arr[j]>=0&&w-arr[i]-arr[j]<MAX&&ww[w-arr[i]-arr[j]]>j){
				chk = true;
				// cout<<i<<" "<<j << " "<<ww[w-arr[i]-arr[j]]<<endl;
				// break;			
			}
		}
		// if(chk)break;
	}
	if(chk)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
		
	
}

