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

int main(){
	FAST
	 char c[6][16]={-1,};
    string s;
    for(int i=0;i<5;i++){
        cin >> s;
        for(int j=0;j<s.length();j++){
            cout<<(int)c[i][j];
            c[i][j]=s[j];
        }
    }
    
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(c[j][i] == -1){continue;}
            cout << c[j][i];
        }
    }
	
}


