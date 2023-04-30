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
ll nCr(int r){
	ll cur = 1;
	for (int i = 13; i >13-r; i--)
	{
		cur*=i;
	}
	for (int i = 1; i <=r; i++)
	{
		cur/=i;
	}
	return cur;
	
}
int main()
{
	FAST
	bool dp[53][14][14][14][14];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0] = true;
	for (int cnt = 0; cnt < 52; cnt++)
	{
		for (int heart = 0; heart < 14; heart++)
		{
			for (int spade = 0; spade < 14; spade++)
			{
				for (int dia = 0; dia < 14; dia++)
				{
					for (int club = 0; club < 14; club++)
					{
						if(heart+1<=13){
							dp[cnt+1][heart+1][spade][dia][club]|=dp[cnt][heart][spade][dia][club];
						}
						if(spade+1<=13){
							dp[cnt+1][heart][spade+1][dia][club]|=dp[cnt][heart][spade][dia][club];
						}
						if(dia+1<=13){
							dp[cnt+1][heart][spade][dia+1][club]|=dp[cnt][heart][spade][dia][club];
						}
						if(club+1<=13){
							dp[cnt+1][heart][spade][dia][club+1]|=dp[cnt][heart][spade][dia][club];
						}
					}
					
				}
				
			}
			
		}

		
	}
	int n;
	cin >> n;
	ll ans = 0;
	
	for (int heart = 1; heart < 14; heart++)
	{
		for (int spade = 1; spade < 14; spade++)
		{
			for (int dia = 1; dia < 14; dia++)
			{
				for (int club = 1; club < 14; club++)
				{
					if(dp[n][heart][spade][dia][club]){
						cout<<heart<<" "<<spade<<" "<<dia<<" "<<club<<endl;
						ans+=nCr(heart)*nCr(spade)*nCr(dia)*nCr(club);
					}ans%=10007;
				}
				
			}
			
		}
		
	}
	cout<<ans<<endl;
	
}