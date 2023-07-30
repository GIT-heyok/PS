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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
vector<int> pi(1000001);

void failure(string s){
    int m = 0;
    int begin = 1;
    while(begin+m<s.length()){
        if(s[begin+m]==s[m]){
            m++;
            pi[begin+m-1]=m;
        }
        else{
            if(m==0)begin++;
            else begin+=m-pi[m-1],m=pi[m-1];
        }
    }
}
int main()
{
    FAST
    int l;
    cin >> l;
    string s;
    cin >> s;
    failure(s);
    cout<<s.length()-pi[s.length()-1]<<endl;
}