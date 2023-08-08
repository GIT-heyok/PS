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
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
vector<int> pi(1000001);
int main()
{
    FAST
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    int visited[f+1];
    for (int i = 0; i < f+1; i++)
    {
        visited[i] = inf;
    }
    visited[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now+u<=f&&visited[now+u]>visited[now]+1){
            visited[now+u] = visited[now]+1;
            q.push(now+u);
        }
        
        if(now-d>=1&&visited[now-d]>visited[now]+1){
            visited[now-d] = visited[now]+1;
            q.push(now-d);
        }
    }

    if(visited[g]>=inf){
        cout<<"use the stairs"<<endl;
    }
    else{
        cout<<visited[g]<<endl;
    }
    
}