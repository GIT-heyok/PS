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
/*
Point 1. when there are more toys, you should count it!
Point 2.	3 -> 9C3*6C3
			2 -> 8C2
			(I manually did it in this code: two, three arrays)
*/
int main()
{
	FAST
	int N, R, G, B;
	cin >> N >> R >> G >> B;
	ll memo[N+1][R+1][G+1][B+1];
	fill(&memo[0][0][0][0], &memo[N][R][G][B+1], 0);
	memo[0][0][0][0] = 1;
	ll two[6] = {0,2,6,20,70,252};
	ll three[4] = {0,6,90,1680};
	for (int i = 1; i <= N; i++)
	{
		for (int r = 0; r <= R; r++)
		{
				for (int g = 0; g <= G; g++)
				{
					for (int b = 0; b <= B; b++)
					{
						if(i%3==0){
							int add = i/3;
							if(r+add<=R&&g+add<=G&&b+add<=B){
								memo[i][r+add][g+add][b+add]+=memo[i-1][r][g][b]*three[add];
							}
						}

						if(i%2==0){
							int add = i/2;
							if(r+add<=R&&g+add<=G){
								memo[i][r+add][g+add][b]+=memo[i-1][r][g][b]*two[add];
							}
							if(g+add<=G&&b+add<=B){
								memo[i][r][g+add][b+add]+=memo[i-1][r][g][b]*two[add];
							}
							if(r+add<=R&&b+add<=B){
								memo[i][r+add][g][b+add]+=memo[i-1][r][g][b]*two[add];
							}
						}

						if(i%1==0){
							int add = i;
							if(r+add<=R){
								memo[i][r+add][g][b]+=memo[i-1][r][g][b];
							}
							if(g+add<=G){
								memo[i][r][g+add][b]+=memo[i-1][r][g][b];
							}
							if(b+add<=B){
								memo[i][r][g][b+add]+=memo[i-1][r][g][b];
							}
						}
					}
					
				}
		}
		
	}
	ll ans = 0;
	ll sum = (N)*(N+1)/2;
	for (int r = 0; r <= R; r++)
	{
		for (int g = 0; g < G+1; g++)
		{
			for (int b = 0; b < B+1; b++)
			{
				if(sum<=r+g+b){
					ans+=memo[N][r][g][b];
				}
			}
			
		}
		
	}
	cout<<ans<<endl;
	
}