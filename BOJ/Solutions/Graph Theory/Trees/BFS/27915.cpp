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
const int MAX = 100001;
const ll INF = 1e12;

int n;
vector<int> tree[MAX];
vector<int> visited(MAX, 0);
int bfs(int a){
	int odd = 0;
	int even = 0;
	queue<int> q;
	q.push(a);
	visited[a] = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(visited[cur]%2){
			// cout<<cur<<" "<<visited[cur]<<endl;
			odd++;
		}
		else {even++;
			// cout<<cur<<" "<<visited[cur]<<endl;
		}
		int lvl = visited[cur];
		for (int i = 0; i < tree[cur].size(); i++)
		{
			int nxt = tree[cur][i];
			visited[nxt] = lvl+1;
			q.push(nxt);
		}
	}
	// cout<<odd<<" "<<even<<endl;
	return max(odd,even);
}
int main()
{
    FAST
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int k;
		cin >> k;
		tree[k].push_back(i);
	}
	cout<<bfs(1)<<endl;
}
    


