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

const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
ll distance(pD a, pD b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int main(){
	FAST
    int n;
    cin >> n;
    vector<pLL> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first>> points[i].second;
    }
    pD p1 = points[0];
    ll ans = INF;
    for (int i = 0; i < n; i++)
    {
        ll dist = 0;
        ll midx = 0;
        for (int j = 0; j < n; j++)
        {
            if(dist<distance(points[i], points[j])){
                dist = distance(points[i], points[j]);
                midx = i;
            }
        }
        if(ans>dist){
            ans = dist;
            p1 = points[midx];
        }
    }
    cout<<p1.first<<" "<<p1.second<<endl;
    
}


