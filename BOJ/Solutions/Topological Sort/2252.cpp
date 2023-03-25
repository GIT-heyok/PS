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
const int MAX = 32001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

vector<int> tree[MAX];

vector<bool> visited(MAX, false);
stack<int> st;
vector<int> ans;
int n, m;
void dfs(int here) {
	visited[here] = true;
	
	for (int there = 0; there < tree[here].size(); there++) {
		if (!visited[tree[here][there]])
			dfs(tree[here][there]);
	}
	ans.push_back(here);

}


void topologicalSort() {

	for (int i = 1;i<=n;i++)
		if (!visited[i]) dfs(i);

	//종료된 순서를 거꾸로 만든다.
	reverse(ans.begin(), ans.end());
}
int main(){
	FAST
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >>b;
		tree[a].push_back(b);
	}
	topologicalSort();
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	
	
	

	
}
