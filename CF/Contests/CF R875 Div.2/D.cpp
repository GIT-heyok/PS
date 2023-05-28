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
const int MAX = 500001;
const ll INF = 1234567890ll;

int main()
{
    FAST int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pLL> arr(n);
        vector<pair<pLL,int>> arrTwo(n);
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
               cin >> arr[i].first;
            cnt[arr[i].first]++;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }
        sort(all(arr));
        for (int i = 0; i < n; i++)
        {
                arrTwo[i].first.second = arr[i].first;
                arrTwo[i].first.first = arr[i].second;
                arrTwo[i].second = i;
        }
        
        vector<int> chk;
        for (int i = 0; i < n+1; i++)
        {
            if(cnt[i])chk.push_back(i);
        }
        
        sort(all(arrTwo));
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll curA = arr[i].first;
            ll curB = arr[i].second;
            if(curA*curA>2*n)break;
            // different value
            for (int j: chk)
            {
                if (curA * j > 2 * n)
                    break;
                if (curA * j - curB > n)
                    continue;
                if(curA*j-curB<=0)continue;
                
                if (j==curA&&curA * j - curB < curB)
                    continue;
                pair<pLL, int> lbb = {{curA * j - curB,j},i+1};
                pair<pLL, int> ubb = {{curA * j - curB,j},n};
                ans += upper_bound(all(arrTwo), ubb) - lower_bound(all(arrTwo), lbb);
                
                
                // cout << curA << " " << j << " "<<ans <<endl;
            }
        }

        cout << ans << endl;
    }
}