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

struct mat2D
{
	ll **ppi;
	int r, c;
	//default matrix
	mat2D(int n){
		r=n;
		c=n;
		ppi = (ll**)malloc(sizeof(ll*)*n);
		for (int i = 0; i < n; i++)
		{
			ppi[i] = (ll*)malloc(sizeof(ll)*n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i==j)ppi[i][j] = 1;
				else ppi[i][j] = 0;
			}
		}
	}
	
	mat2D(int n, int m){
		r = n;
		c = m;
		ppi = (ll**)malloc(sizeof(ll*)*n);
		for (int i = 0; i < n; i++)
		{
			ppi[i] = (ll*)malloc(sizeof(ll)*m);
		}
		fill();
	}

	mat2D(vector<vll>& vec){
		r = vec.size();
		c = vec[0].size();
		ppi = (ll**)malloc(sizeof(ll*)*r);
		for (int i = 0; i < r; i++)
		{
			ppi[i] = (ll*)malloc(sizeof(ll)*c);
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				ppi[i][j] = vec[i][j];
			}
			
		}
		
	}

	// ~mat2D(){
	// 	for (int i = 0; i < r; i++)
	// 	{
	// 		delete ppi[i];
	// 	}
	// 	delete ppi;
	// }

	mat2D operator*(mat2D& other);

	void fill(){
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				ppi[i][j] = 0;
			}
			
		}
	}
	void print(){
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout<<ppi[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};

mat2D mat2D::operator*(mat2D &a){
	mat2D ans(r, a.c);
	if(c!=a.r){
		cout<<"!!"<<endl;
		return ans;
	}
	else{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < a.c; j++)
			{
				for (int k = 0; k < c; k++)
				{
					ans.ppi[i][j] += ppi[i][k]*a.ppi[k][j];
					ans.ppi[i][j]%=MOD;
				}
				
			}
			
		}
		return ans;
		
	}
}

mat2D exponentiation(mat2D& m, ll a){
	mat2D ans(m.r);
	if(a==0)return ans;
	else{
		if(a%2==0){
			ans = exponentiation(m,a/2);
			ans =ans*ans;
			return ans;
		}
		else{
			ans = exponentiation(m,a/2);
			ans = ans*ans;
			ans = ans*m;
			return ans;
		}
	}
}

int main()
{
    FAST
	
	int n;
	ll m;
	cin >> n >> m;
	vector<vll> aa(n, vll(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> aa[i][j];
		}
	}
	mat2D ans(aa);
	ans = exponentiation(ans, m);
	ans.print();
	
	
}
	


    


