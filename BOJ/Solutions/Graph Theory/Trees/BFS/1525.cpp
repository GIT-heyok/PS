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

ll arrToNum(vector<vector<int>> vec){
	ll num = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num = num<<4;
			num+=vec[i][j];
		}
	}
	return num;
}

vector<vi> numToArr(ll n){
	vector<vi> vec(3, vector<int>(3));
	for (int i = 2; i >= 0; i--)
	{
		for (int j = 2; j >= 0; j--)
		{
			vec[i][j] = n%16;
			n = n>>4;
		}
		
	}
	return vec;
	
}
//bfs + hashing: array -> number cause it is possible! ans bfs
int main(){
	FAST
	map<ll, int> visited;

	vector<vi> temp(3, vi(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = i*3+j+1;
			if(i==2&&j==2)temp[i][j] = 0;
		}
	}
	ll num = arrToNum(temp);
	// cout<<num<<endl;
	vector<vi> destArr(3, vector<int>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> destArr[i][j];
		}
	}
	ll dest = arrToNum(destArr);
	visited[num] = 1;
	queue<ll> q;
	int ans = -1;
	q.push(num);
	int dr[4] = {-1,1,0,0};
	int dc[4] = {0,0,-1,1};
	while(!q.empty()){
	
		ll cur = q.front();
		q.pop();
		if(cur==dest){
			ans = visited[cur]-1;
			break;
		}
		vector<vi> chk = numToArr(cur);
		// for (int i = 0; i < 3; i++)
		// {
		// 	for (int j = 0; j < 3; j++)
		// 	{
		// 		cout<<chk[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(chk[i][j]==0){
					for (int k = 0; k < 4; k++)
					{
						int nr = i+dr[k];
						int nc = j+dc[k];
						if(nr>=0&&nr<3&&nc>=0&&nc<3){
							chk[i][j] = chk[nr][nc];
							chk[nr][nc] = 0;
							ll nxtNum = arrToNum(chk);
							if(!visited[nxtNum]){
								visited[nxtNum] = visited[cur]+1;
								q.push(nxtNum);
							}
							chk[nr][nc] = chk[i][j];
							chk[i][j] = 0;
						} 
					}
					
				}				
			}
			
		}
		
	}
	cout<<ans<<endl;

}

