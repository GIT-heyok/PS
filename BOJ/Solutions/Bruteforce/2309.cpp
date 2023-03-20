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
	int arr[9];
	
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sum -=100;
	vi ans;
	bool chk = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if(arr[i]+arr[j]==sum){
				for (int k = 0; k < 9; k++)
				{
					if(k!=i&&k!=j){
						ans.push_back(arr[k]);
					}
				}
				chk = true;
			}
		if(chk)break;
		}
		if(chk)break;
	}
	sort(all(ans));
	for (int i = 0; i < 7; i++)
	{
		cout<<ans[i]<<endl;
	}
	

	
}


