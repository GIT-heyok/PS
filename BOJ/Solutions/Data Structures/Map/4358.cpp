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
typedef pair<double, double> pD;

const int MAX = 101;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;

int main(){
	FAST
    map<string, int> ma;
    string s;
    double cnt = 0;
    while(getline(cin, s)){
        ma[s]++;
        cnt++;
    }
    cout<<setprecision(4);
    cout<<fixed;
    for (auto iter = ma.begin(); iter !=ma.end(); iter++)
    {
        
        cout<< iter->first << " "<< (double)iter->second/cnt*100<<endl;
    }
    
    
}


