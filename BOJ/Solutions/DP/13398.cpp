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
const ll MOD = 1000;

//never thought of doing front + back...



int main()
{
    FAST
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vi front(n);
	int curMx = arr[0]; 
	front[0] = curMx;
	for (int i = 1; i < n; i++)
	{
		curMx = max(curMx+arr[i], arr[i]);
		front[i] = curMx;
	}
	vi back(n);
	curMx = arr[n-1];
	back[n-1] = curMx;
	int ans = arr[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		curMx = max(curMx+arr[i], arr[i]);
		back[i] = curMx;
		ans = max(ans, back[i]);
	}
	
	//for (int i = 0; i < n; i++)
	//{
		//cout<<front[i]<<" ";
	//}
	//cout<<endl;
	
	
	//for (int i = 0; i < n; i++)
	//{
		//cout<<back[i]<<" ";
	//}
	for (int i = 0; i < n-2; i++)
	{
		ans = max(ans, front[i]+back[i+2]);
	}
	
	cout<<ans<<endl;
}
	


    


