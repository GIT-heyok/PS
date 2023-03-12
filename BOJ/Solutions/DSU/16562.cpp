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
// #define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 10001;
const ll INF = 1e9;
int n, m, k;
int parent[MAX];
ll cost[MAX];

int find(int a){
    if(parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    // cout<<a<<"m"<<
    // b<<endl;
    if(a>b){
        swap(a, b);
    }
    parent[b] = a;
}

int main()
{
    FAST 
    cin >> n >> m >> k;
    fill(cost, cost+n+1, INF);
    // cout<<"!!!"<<endl;
    ll price[n+1];
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
// cout<<"!!!"<<endl;

    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
    // cout<<find(a)<<"f"<<find(b)<<endl;
        merge(a, b);
        // cout <<a << b<< endl;
    }

    // cout<<"!!!"<<endl;
    // for (int i = 0; i < n+1; i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    
    for (int i = 1; i <= n; i++)
    {
        ll pr = price[i];
        int par = find(i);
        cost[par] = min(cost[par], pr);
    }
    // cout<<"!"<<endl;
    ll curP=0;
    for (int i = 1; i <= n; i++)
    {
        if(cost[i]<INF)curP+=cost[i];
    }
     
    if(curP>k)cout<<"Oh no"<<endl;
    else cout<<curP<<endl;
    

}

