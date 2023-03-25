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
const int MAX = 3001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
bool arr[MAX][MAX];
bool visited[MAX];
int n;
bool dfs(int k){
	if(visited[k])return false;
	visited[k] = true;
	for (int i = 0; i < n; i++)
	{
		if(arr[k][i]){
			dfs(i);
		}
	}
	return true;
}


int main(){
	FAST
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int x[n], y[n],r[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i] >> r[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				int dx = x[i]-x[j], dy = y[i]-y[j], dr = r[i]+r[j];
				if(dx*dx+dy*dy<=dr*dr){
					arr[i][j] = true;
					arr[j][i] = true;
				}
			}			
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if(dfs(i))ans++;
		}
		cout<<ans<<endl;
		

		
		
	}
}


