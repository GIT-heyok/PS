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
int main()
{
    FAST 
    int n;
    cin>>n;
    int mn[3], mx[3];
    mn[0] = 0;
    mn[1] = 0;
    mn[2] = 0;
    mx[0] = 0;
    mx[1] = 0;
    mx[2] = 0;
    
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >>b >>c;
        int mnp0 = mn[0];
        int mnp1 = mn[1];
        int mnp2 = mn[2];
        int mxp0 = mx[0];
        int mxp1 = mx[1];
        int mxp2 = mx[2];

        mn[0] = a + min(mnp0, mnp1);
        mn[1] = b + min(mnp0 ,min(mnp1, mnp2));
        mn[2] = c + min(mnp1, mnp2); 
        mx[0] = a + max(mxp0, mxp1);
        mx[1] = b + max(mxp0 ,max(mxp1, mxp2));
        mx[2] = c + max(mxp1, mxp2);}
    cout<<max(mx[0], max(mx[1], mx[2]))<<" ";
    cout<<min(mn[0], min(mn[1], mn[2]))<<endl;
}

