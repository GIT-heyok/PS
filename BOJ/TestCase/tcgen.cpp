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
#include <random>

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
const int MAX = 300001;
const ll INF = 1e12;
int main()
{
  std::random_device rd;

  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> dis(1, 2000);

    FAST
	freopen("input.txt", "w", stdout);
	cout<<"300000 2 1"<<endl;
	int cur = 1;
	for(int i = 0; i < 300000; i++)
	{
		cur+=dis(gen);
		cout<<cur<<" ";
	}
	cout<<endl;
	cout<<"2"<<endl;
		
		
}
    


