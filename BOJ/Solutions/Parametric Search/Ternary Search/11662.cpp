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
double ax, ay, bx, by, cx, cy, dx, dy;

double getDist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double ternarySearch(){
    double start = 0;
    double end = 1;
    int iter = 500;
    double anss = 1e8;
    while(iter--){
        double lb = (2*start+end)/3;
        double ub = (start+2*end)/3;
        double lValAx = ax+(bx-ax)*lb;
        double lValAy = ay+(by-ay)*lb;
        double lValCx = cx+(dx-cx)*lb;
        double lValCy = cy+(dy-cy)*lb;
        double uValAx = ax+(bx-ax)*ub;
        double uValAy = ay+(by-ay)*ub;
        double uValCx = cx+(dx-cx)*ub;
        double uValCy = cy+(dy-cy)*ub;
        double lAns = getDist(lValAx, lValAy, lValCx, lValCy);
        double uAns = getDist(uValAx, uValAy, uValCx, uValCy);
        anss = min(anss, lAns);
            if(lAns>uAns){
                start = lb;
            }
            else{
                end = ub;
            }
    }
    return anss;
}

int main()
{
    FAST
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    cout<<setprecision(15)<<fixed;
    cout<<ternarySearch();
}

