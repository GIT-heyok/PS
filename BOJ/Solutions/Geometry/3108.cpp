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
const int MAX = 1001;
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
	cin >> n;
	int x1[n], x2[n], y1[n], y2[n];
	bool chk = false;
	for (int i = 0; i < n; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if(x1[i]>x2[i])swap(x1[i], x2[i]);
		if(y1[i]>y2[i])swap(y1[i], y2[i]);
		if(((x1[i]<=0&&x2[i]>=0)&&(y1[i]==0||y2[i]==0))||(x1[i]==0||x2[i]==0)&&(y1[i]<=0&&y2[i]>=0)){
			chk = true;}
	}

	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = false;
		}
		
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(x1[i]<x1[j]&&x2[i]>x2[j]&&y1[i]<y1[j]&&y2[i]>y2[j]){

			}
			else if(x1[j]<x1[i]&&x2[j]>x2[i]&&y1[j]<y1[i]&&y2[j]>y2[i]){

			}
			else if(x2[i]<x1[j]||y2[i]<y1[j]||y2[j]<y1[i]||x2[j]<x1[i]){

			}
			else{
				arr[i][j] = true;
				arr[j][i] = true;
			}

			
		}
		
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
		
	// }
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if(dfs(i))ans++;
	}
	if(chk)ans--;
	cout<<ans<<endl;
	
	
}


