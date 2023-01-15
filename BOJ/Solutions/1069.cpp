#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int MAX = 500001;
const int INF = 1234567890;

ld getsqdist(ld x1, ld y1, ld x2, ld y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
ld getdist(ld x1, ld y1, ld x2, ld y2){
    return sqrt(getsqdist(x1, y1, x2, y2));
}

int main()
{
    FAST
    cout<<setprecision(15);
    ld x,y, d,t ;
    cin >> x>> y >> d>>t;
        ld xyDis = getdist(x,y,0,0);
        ll distWent1 = (ll) xyDis/(ll)d*(ll)d;
        ll distWent2 = ((ll) xyDis/(ll)d*(ll)d)+d;
        ll distWent3 = ((ll) xyDis/(ll)d*(ll)d)+2*d;
        ld distLeft1 = xyDis - distWent1;
        ld distLeft2 = distWent2 - xyDis;
        ld ans1 = distWent1/d*t;
        ld ans2 = distWent2/d*t;;
        ld ans3 = distWent3/d*t;
        if(distWent2/d==1){
            ans2 += distLeft2;
        }
        ans1+=distLeft1;
        ld ans = min(xyDis,min(min(ans2, ans3), ans1));
        cout<<ans<<endl; 

}