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
const int MAX = 500001;
const int INF = 123456780;


int main()
{
    FAST
    int n;
    cin >> n;
    int arr[n][4];
    for(int i=0; i<n; i++){
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }   
    }
    vi l, r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            l.push_back(arr[i][0]+arr[j][1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            r.push_back(arr[i][2]+arr[j][3]);
        }
    }
    sort(all(r));
    ll ans = 0;
    for(int i=0; i<l.size(); i++){
        ans += upper_bound(all(r), -l[i])-lower_bound(all(r),-l[i]);
    }
    cout<<ans<<endl;
}