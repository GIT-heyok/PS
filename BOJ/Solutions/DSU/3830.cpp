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
int diff[MAX];
int find(int x){
	if(parent[x]==x){
		return x;
	}
	int pp = find(parent[x]);
	diff[x]+=diff[parent[x]];
	return parent[x] = pp;
}


void merge(int x, int y, int d){
	int a = find(x);
	int b = find(y);
	if(a==b)return;
	diff[b] = diff[x]-diff[y]+d;
	parent[b] = a;
}

int ddd(int x, int y){
	int a = find(x);
	int b = find(y);
	if(a!=b){
		return -inf;
	}
	return diff[y]-diff[x];
}

int main(){
	FAST
	int n, m;
	cin >> n >> m;
	while(n!=0&&m!=0){
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
			diff[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			string s; 
			int a, b;
			cin >> s >> a >> b;
			if(s=="!"){
				int d;
				cin >> d;
				merge(a,b,d);
			}
			else{
				int d = ddd(a,b);
				if(d<=-inf){
					cout<<"UNKNOWN"<<endl;
				}
				else cout<<d<<endl;
			}
			
			
		}
		cin >> n >> m;
	}	
	

	
}


