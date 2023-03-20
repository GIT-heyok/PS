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

int q[6];
void setNthelem(vi& arr, int ind, int n){
	if(n==5){
		q[n] = arr[ind];
		for (int i = 0; i < 6; i++)
		{
			cout<<q[i]<<" ";
		}
		cout<<endl;
	}
	else{
		q[n] = arr[ind];
		for (int i = ind+1; i < arr.size(); i++)
		{
			setNthelem(arr, i, n+1);
		}
	}
}
int main(){
    FAST
	int n;
	cin >> n;
	while(n!=0){
		vi arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++)
		{
			setNthelem(arr, i, 0);
		}
		
		cin >> n;
	}	
}


