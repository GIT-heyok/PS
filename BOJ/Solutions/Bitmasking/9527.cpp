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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;

ll onesKDigit[55];
ll getOnes(ll a){
    if(a==0)return 0;
    else if(a==1)return 1;
    int firstDig = 0;
    for (int i = 54; i >= 0; i--)
    {
        if(a-(1LL<<i)>=0){
            firstDig = i;
            break;
        }   
    }
    return onesKDigit[firstDig]+a-(1LL<<firstDig)+1+getOnes(a-(1LL<<firstDig));   
}
int main()
{
    FAST
    onesKDigit[1] = 1;
    for (int i =1; i < 54; i++)
    {
        onesKDigit[i+1] = 2*onesKDigit[i]+(1LL<<i);
    }
    ll a, b;
    cin >> a >> b;
    cout<<getOnes(b)-getOnes(a-1)<<endl;
    
    
}


