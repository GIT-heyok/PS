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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int arr[128][128];
int w=0, b=0;

void divide(int r1, int c1, int r2, int c2){
	// cout<<r1<<" "<<c1<<" "<<r2<< " "<<c2<<endl;
	int start = arr[r1][c1];
	bool chk = false;
	for (int i = r1; i < r2; i++)
	{
		for (int j = c1; j < c2; j++)
		{
			if(arr[i][j]!=start){
				chk = true;
			}
		}
		
	}
	if(chk){
		divide(r1,c1,(r1+r2)/2, (c1+c2)/2);
		divide(r1,(c1+c2)/2, (r1+r2)/2, c2);
		divide((r1+r2)/2,c1,r2, (c1+c2)/2);
		divide((r1+r2)/2,(c1+c2)/2, r2, c2);
	}
	else{
		if(start==0){
			w++;
		}
		else{
			b++;
		}
	}
	
}

int main(){
	FAST
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
		
	}
	divide(0,0,n,n);
	cout<<w<<endl<<b<<endl;
	
}


