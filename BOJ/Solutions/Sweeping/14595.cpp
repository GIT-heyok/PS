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
const int INF = 1234567890;
int main()
{
    FAST int n;
    cin >> n;
    int ans = n;
    int q;
    cin >> q;
    vector<pI> vec(q);
    if (q == 0)
    {
        cout << ans << endl;
    }
    else
    {
        for (int i = 0; i < q; i++)
        {
            cin >> vec[i].first >> vec[i].second;
        }
        sort(all(vec));
        int start = vec[0].first, end = vec[0].second;
        for (int i = 1; i < q; i++)
        {
            if (vec[i].first > end)
            {
                ans -= (end - start);
                start = vec[i].first;
                end = vec[i].second;
            }
            else
            {
                end = max(vec[i].second, end);
            }
        }
        ans -= (end - start);
        cout << ans << endl;
    }
}
