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
int n, m;
vector<int> graph[MAX+1];
vector<int> graphTwo[MAX+1];
bool chk[MAX+1];
bool chkTwo[MAX+1];

void dfs(int node){
    if(!chk[node]){
        chk[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];
            dfs(nextNode);
        }   
    }
}

void dfsTwo(int node){
    if(!chkTwo[node]){
        chkTwo[node] = true;
        for (int i = 0; i < graphTwo[node].size(); i++)
        {
            int nextNode = graphTwo[node][i];
            dfsTwo(nextNode);
        }   
    }
}

int main()
{
    FAST
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphTwo[b].push_back(a);
    }
    dfs(1);
    dfsTwo(n);
    int t;
    cin >> t;
    while(t--){
        int temp;
        cin >> temp;
        if(chk[temp]&&chkTwo[temp]){
            cout<<"Defend the CTP"<<endl;
        }
        else{
            cout<<"Destroyed the CTP"<<endl;
        }
    }
       
}