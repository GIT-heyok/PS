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

int main(){
    FAST
	int n, s;
	cin >> n >> s;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ans =0;
	for (int i = 1; i < (1<<n); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if(i&(1<<j)){
				sum+= arr[j];
			}
		}
		if(sum==s){
			ans++;
		}
		
	}
	
	cout<<ans<<endl;
	
}


