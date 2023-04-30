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
stack<int> st;
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
    sccCounter = vertexCounter = 0;
    for (int i = 1; i < adj.size(); i++)
    {
        if (discovered[i] == -1)
            scc(i);
    }
    return sccId;
}
int main()
{
    FAST int v, e;
    cin >> v >> e;
    for (int i = 0; i <= v; i++)
    {
        adj.push_back(vector<int>());
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    tarjanSCC();
    cout << sccCounter << endl;
    vector<vector<int>> ans;
    for (int i = 0; i < sccCounter; i++)
    {
        ans.push_back(vector<int>());
    }
    int convert[sccCounter];
    fill(convert, convert + sccCounter, -1);
    int cnt = 0;
    for (int i = 1; i < sccId.size(); i++)
    {
        if (convert[sccId[i]] == -1)
        {
            convert[sccId[i]] = cnt;
            cnt++;
        }
    }

    for (int i = 1; i < sccId.size(); i++)
    {
        ans[convert[sccId[i]]].push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << -1 << endl;
    }

    cout << endl;
}