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

const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e6 + 7;
const int MAX = 1001;

vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
vector<int> sccIndegree;
stack<int> st;
//scc with starting position
int sccCounter, vertexCounter;
int scc(int here)
{
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }

    if (ret == discovered[here])
    {
        while (true)
        {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here)
                break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC()
{
    sccId = discovered = vector<int>(adj.size(), -1);
    sccIndegree = vector<int>(adj.size(), 0);
    sccCounter = vertexCounter = 0;
    for (int i = 1; i < adj.size(); i++)
    {
        if (discovered[i] == -1)
            scc(i);
    }

    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (sccId[adj[i][j]] == sccId[i])
                continue;
            sccIndegree[sccId[adj[i][j]]]++;
        }
    }
    int cnt = 0;
    bool visited[sccCounter];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < sccCounter; i++)
    {
        if(sccIndegree[i]==0)cnt++;
    }
    
    cout<<cnt<<endl;
    return sccId;
}
int main()
{
    FAST int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n+1, vector<int>());
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        tarjanSCC();
    }
}