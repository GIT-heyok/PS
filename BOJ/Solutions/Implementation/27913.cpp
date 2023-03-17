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

int main()
{
    FAST
	int n, q;
	cin >> n >> q;
	bool isCapMOD10[10] = {1,0,0,1,0,0,1,0,0,0};
	bool isCap[n];
	int numCap = 0;
	for (int i = 0; i < n; i++)
	{
		isCap[i] = isCapMOD10[i%10];
		if(isCap[i])numCap++;
	}
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		x--;
		if(isCap[x]){
			numCap--;
			isCap[x] = false;
		}
		else{
			numCap++;
			isCap[x] = true;
		}
		cout<<numCap<<endl;
	}
		
}
    


