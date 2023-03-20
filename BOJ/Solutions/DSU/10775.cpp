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
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int parent[MAX];
int find(int a){
	// cout<<a<<endl;
	if(parent[a]!=a){
		return parent[a] = find(parent[a]);
	}
	else{
		parent[a]--;
		return parent[a]+1;
	}
}
/*not really a disjoint set
kinda like setting pointer to its parent
ex) 3 is occupied -> find(3) = 2 (par[3]=2)
and 4 is occupied -> find(4) = 2 
(find(4) = find(3) -> par[3]=1 and par[4]=1, 
this is possible through recursion)
*/

int main(){
    FAST
	int g, p;
	cin >> g >> p;
	for (int i = 1; i <= g; i++)
	{
		parent[i] = i;
	} 
	
	int ans=0;
	bool chk = false;
	for (int i = 0; i < p; i++)
	{
		int k;
		cin >> k;
		if(!chk&&find(k)){
			ans++;
		}
		else{
			chk = true;
		}
		// for (int i = 1; i <= g; i++)
		// {
		// 	cout<<parent[i]<<" ";
		// }
		// cout<<endl;
		
	}
	cout<<ans<<endl;

}


