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
const int MAX = 10001;
const ll INF = 1e12;

int main()
{
    FAST
	string s1, s2;
	cin >> s1 >> s2;
	int sz1 = s1.length(), sz2 = s2.length();
	int memo[sz1+1][sz2+1];
	for (int i = 0; i <= sz1; i++)
	{
		for (int j = 0; j <= sz2; j++)
		{
			memo[i][j] = 0;
		}
	}
	for (int i = 1; i <= sz1; i++)
	{
		for (int j = 1; j <= sz2; j++)
		{
			if(s1[i-1]==s2[j-1]){
				memo[i][j] = memo[i-1][j-1]+1;
			}
			else{
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
			}
		}
	}
	// for (int i = 0; i < sz1+1; i++)
	// {
	// 	for (int j = 0; j < sz2+1; j++)
	// 	{
	// 		cout<<memo[i][j]<<" ";
	// 	}
	// 	cout<<endl;	
	// }
	
	cout<<memo[sz1][sz2]<<endl;
	
}

    


