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
1,2 and 2,4 and 3,6 are the same.
group them into one by dividing by its gcd's.
*/
int main()
{
    FAST
    int n;
    cin >> n;
    vector<pI> vec(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x==0){
            y/=abs(y);
        }
        else if(y==0){
            x/=abs(x);
        }
        else{
            int gcd = __gcd(abs(x), abs(y));
            x/=gcd;
            y/=gcd;
        }
        vec[i] = {x,y};
    }
    sort(all(vec));
    int sx = 0, sy = 0;
    int cnt = 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if(sx!=vec[i].first||sy!=vec[i].second){
            cnt = 1;
        }
        else{
            cnt++;
            ans = max(ans, cnt);
        }
        sx = vec[i].first;
        sy = vec[i].second;   
    }
    cout<<ans<<endl;
    
    
}

