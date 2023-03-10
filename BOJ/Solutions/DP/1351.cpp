#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>

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
ll n, p, q;
map<ll, ll> m;

ll chk(ll k){
    if(k<=0)return 1;
    if(m[k]>0){
        return m[k];
    }
    return m[k] = chk(k/p)+chk(k/q);
}
int main()
{
    FAST 
    cin >> n >> p >> q;
    cout<<chk(n)<<endl;
}

