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

const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e6 + 7;
const int MAX = 52;
int N, M, C;
ll memoTotal[MAX][MAX];
vector<pI> coord(MAX + 1);
int arr[MAX][MAX];
ll memoTemp[MAX][MAX];
ll memoAtoB[MAX][MAX];
// dp but only s and e is touchable
ll visit(int r, int c, int s, int e)
{
	if (r >= 1 && r <= N && c >= 1 && c <= N)
	{
		if (memoTemp[r][c] != -1)
			return memoTemp[r][c];
		if(r==1&&c==1&&s==0){
			return 1;
		}
		else if (arr[r][c] == -1 || arr[r][c] == e)
		{
			ll &temp = memoTemp[r][c];
			temp = 0;
			temp += visit(r - 1, c, s, e);
			temp += visit(r, c - 1, s, e);
			temp %= MOD;
			return temp;
		}
		else if (arr[r][c] == s){
			return 1;
		}
		
		return 0;
	}
	return 0;
}
ll courseAtoB(int a, int b)
{
	if (memoAtoB[a][b] != -1)
		return memoAtoB[a][b];
	ll &temp = memoAtoB[a][b];
	temp = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = -1;
			memoTemp[i][j] = -1;
		}
	}
	for (int i = 1; i <= C; i++)
	{
		arr[coord[i].first][coord[i].second] = i;
	}
	return temp = visit(coord[b].first, coord[b].second, a, b);
}

//what if arcade is at the middle??
int main()
{
	FAST
			cin >>
		N >> M >> C;
	coord[0] = {1, 1};
	coord[C + 1] = {N, M};
	for (int i = 1; i <= C; i++)
	{
		cin >> coord[i].first >> coord[i].second;
	}
	for (int i = 0; i <= C + 1; i++)
	{
		for (int j = 0; j <= C + 1; j++)
		{
			memoAtoB[i][j] = -1;
			memoTotal[i][j] = 0;
		}
	}
	memoTotal[0][0] = 1;
	for (int i = 1; i <= C + 1; i++)
	{
		for (int j = 0; j <= C+1; j++)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (j > 0)
				{
					memoTotal[i][j] += memoTotal[k][j - 1] * courseAtoB(k, i);
					memoTotal[i][j] %= MOD;
				}
			}
		}
	}
	for (int i = 1; i <= C+1; i++)
	{
		cout<<memoTotal[C+1][i]<<" ";
	}

	cout<<endl;
	for (int i = 0; i <= C+1; i++)
	{
		for (int j = 0; j <= C+1; j++)
		{
			cout<<memoAtoB[i][j]<<" ";
		}
		cout<<endl;
		
	}
	
	// cout<<endl;
	
}