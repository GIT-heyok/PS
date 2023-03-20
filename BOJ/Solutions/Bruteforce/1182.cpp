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

int getSum(vi& arr){
	int sum = 0;
	for (int i = 0; i < arr.size()-1; i++)
	{
		sum+= abs(arr[i]-arr[i+1]);
	}
	return sum;
}
int main(){
    FAST
	int n;
	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(all(arr));
	int ans = 0;
	while(next_permutation(all(arr))){
		ans = max(ans, getSum(arr));
	}
	cout<<ans<<endl;
}


