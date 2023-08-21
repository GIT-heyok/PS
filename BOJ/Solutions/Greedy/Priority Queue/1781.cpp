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
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;

/*
going from the last day, 
and pick ramen with the biggest value
*/
int main()
{
    int n;
    cin >> n;
    vector<pI> vec(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[i] = {a,b};
    }
    vec.push_back({0,0});
    sort(all(vec));
    int current = vec[n].first;
    int ans = 0;
    priority_queue<int> pq;
    //auto f = [&](pI a){cout<<a.first<<" "<<a.second<<endl;};
    for (int i = n; i >=0; i--)
    {
    //   f(vec[i]);
        while(current>vec[i].first&&!pq.empty()){
            ans+=pq.top();
            //cout<<pq.top()<<endl;
            pq.pop();
            current--;
        }
        current = vec[i].first;
        pq.push(vec[i].second);
    }
    cout<<ans<<endl;
    
    

}