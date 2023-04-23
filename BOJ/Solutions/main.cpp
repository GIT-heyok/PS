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

const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;
int dist(pI a, pI b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main()
{
    FAST;
    int n, k;
    cin >> n >> k;
    vector<pI> coord(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }
    ll memo[n][k+1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            memo[i][j] = INF;
        }   
    }
    memo[0][0] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if(i+j+1<n){
                memo[i+j+1][j] = min(memo[i][j]+dist(coord[i], coord[i+j+1]), memo[i+j+1][j]);
            }       
        }   
    }
    cout<<memo[n-1][k]<<endl;
    

    
    
}