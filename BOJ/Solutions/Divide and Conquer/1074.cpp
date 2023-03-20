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

//divide and conquer

int divide(int depth, int r1, int c1, int r2, int c2, int r, int c){
	//cout<<depth<<" "<<r1<<" "<<c1<<" "<<r2 << " "<<c2<<endl;
	if(depth==-1)return 0;
	int plus = 1<<depth;
	int add = plus*plus;
	if(r<r1+plus){
		// O O
		// X X
		if(c<c1+plus){
			// O X
			// X X : 0
			return divide(depth-1, r1, c1, r1+plus, c1+plus, r, c);
		}
		else{
			// X O
			// X X : 1
			return add+divide(depth-1, r1, c1+plus, r1+plus, c2, r, c);
		}
	}
	else{
		// X X
		// O O
		if(c<c1+plus){
			//2
			return 2*add+divide(depth-1, r1+plus, c1, r2, c1+plus, r, c);
		}
		else{
			return 3*add+divide(depth-1, r1+plus, c1+plus, r2, c2, r, c);
		}
	}
}

int main()
{
    FAST
	int n, r, c;
	cin >> n >> r >>c;
	cout<<divide(n-1,0,0,1<<n,1<<n,r,c);
}
	


    


