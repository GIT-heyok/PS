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


/* 
author: hyeok2044
Written at 2023-03-18 19:51
Problem: 11723
Problem Name: 집합
Link: https://www.acmicpc.net/problem/11723
Memo: bit manipulation
*/


int main()
{
    FAST
	int m;
	cin >> m;
	int arr = 0;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin>>s;
		if(s=="add"){

			int temp;
			cin >> temp;
			temp--;
			arr|=(1<<temp);
		}
		else if(s=="remove"){

			int temp;
			cin >> temp;
			temp--;
			arr&=(~(1<<temp));
		}
		else if(s=="check"){

			int temp;
			cin >> temp;
			temp--;
			cout<<!!(arr&(1<<temp))<<endl;
		}
		else if(s=="toggle"){
			int temp;
			cin >> temp;
			temp--;
			arr^=(1<<temp);
		}
		else if(s=="all"){
			arr = (1<<20)-1;
		}
		else{
			arr = 0;
		}
		//cout<<arr<<endl;
	}
	
}
	


    


