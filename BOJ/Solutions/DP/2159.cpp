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
#include <memory.h>

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
typedef pair<double, double> pD;

const int MAX = 5001;
const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e9+7;
//using dp in five different possible spots!
int main()
{
	int dr[5] = {0,0,0,-1,1};
	int dc[5] = {0,-1,1,0,0};
	int n;
	cin >> n;
	n++;
	int coord[n][2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> coord[i][j];
		}
	}
	ll memo[n][5];
	fill(&memo[0][0], &memo[n-1][5],INF);
	memo[0][0]=0;
	for (int i = 0; i < n-1; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			int curr = coord[i][0]+dr[j];
			int curc = coord[i][1]+dc[j];
			for (int k = 0; k < 5; k++)
			{
				int nxtr = coord[i+1][0]+dr[k];
				int nxtc = coord[i+1][1]+dc[k];
				memo[i+1][k] = min(memo[i+1][k],memo[i][j]+abs(curr-nxtr)+abs(curc-nxtc));
			}	
		}
		
	}
	ll ans = INF;
	for (int j = 0; j < 5; j++)
	{
		ans = min(ans, memo[n-1][j]);
	}
	cout<<ans<<endl;
	
	
	
}
