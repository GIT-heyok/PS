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
const ll INF = 1234567890123ll;

int main()
{
    FAST
    int n, l;
    cin >> n >> l;
    priority_queue<pI,vector<pI>, greater<pI>> p;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        p.push({temp, i});
        //cout<<max(i-l,0)<<endl;
        while(p.top().second<=max(i-l,-1)){
            p.pop();
        }
        cout<<p.top().first<<" ";
    }
    cout<<endl;
    
}

