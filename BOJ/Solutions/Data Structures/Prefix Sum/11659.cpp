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
    int n, m;
    cin >> n >> m;
    ll arr[n+1];
    for (int i = 1; i < n+1; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i+1] += arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout<<arr[b]-arr[a-1]<<endl;
    }
    
    

    

}