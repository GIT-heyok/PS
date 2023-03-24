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


int main(){
	FAST
	priority_queue<pI> pq;
	int n;
	cin >> n;
	while(n--){
		int a;
		cin >> a;
		if(a==0){
			if(pq.empty()){
				cout<<0<<endl;
			}
			else{
				cout<<pq.top().first*pq.top().second<<endl;
				pq.pop();
			}
		}
		else{
			if(a>0){
				pq.push({-a, -1});
			}
			else{
				pq.push({a, 1});
			}
		}
	}
}

