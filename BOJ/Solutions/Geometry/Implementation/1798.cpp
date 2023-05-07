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

/*
Implementation
*/
constexpr double const_pi() { return std::atan(1)*4; }

int main()
{
    FAST
    double r, h, d1, A1, d2, A2;
    cout<<setprecision(2)<<fixed;
    while(cin >> r >> h >> d1 >> A1 >> d2 >> A2){
        double R = sqrt(h*h+r*r);
        double T = 2*const_pi()*r/R;
        A2 = abs(A1-A2);
        if(A2>180)A2 = 360-A2;
        double ans = sqrt((d1*d1+d2*d2)-2*d1*d2*cos(A2/180*T/2));
        cout<<ans<<endl;
    }
    
}


