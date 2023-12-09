#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

const int MAX_V = 502;
const int INF = 987654321;
const int FOOD = 250;

int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int work[MAX_V];
int level[MAX_V];


vector<int> adj[502];

int S = 0, T = 500;


bool bfs()
{
    fill(level, level + MAX_V, -1);

    level[S] = 0;

    queue<int> q;

    q.push(S);

    while (!q.empty())
    {
        int here = q.front();
        q.pop();

        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];

            if (level[next] == -1 && c[here][next] - f[here][next] > 0)
            {
                level[next] = level[here] + 1;
                q.push(next);
            }
        }
    }

    return level[T] != -1;
}

int dfs(int here, int flow)
{
    if (here == T)
        return flow;

    for (int &i = work[here]; i < adj[here].size(); i++)
    {
        int next = adj[here][i];

        if (level[next] == level[here] + 1 && c[here][next] - f[here][next] > 0)
        {
            int ret = dfs(next, min(c[here][next] - f[here][next], flow));

            if (ret > 0)
            {
                f[here][next] += ret;
                f[next][here] -= ret;

                return ret;
            }
        }
    }

    return 0;
}

int main()
{
    FAST
    int n, k, d;
    cin >> n >> k >> d;

    for (int i = 1; i <= n; i++)
    {
        c[S][i] = k;

        adj[S].push_back(i);
        adj[i].push_back(S);
    }

    for (int i = 1; i <= d; i++)
    {
        int val;
        cin >> val;

        c[i + FOOD][T] = val;
        adj[i + FOOD].push_back(T);
        adj[T].push_back(i + FOOD);
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            int pos;
            cin >> pos;

            c[i][pos + FOOD] = 1;

            adj[i].push_back(pos + FOOD);
            adj[pos + FOOD].push_back(i);
        }
    }


    int totalFlow = 0;

    while (bfs())
    {
        fill(work, work + MAX_V, 0);

        while (1)
        {
            int flow = dfs(S, INF);
            if (flow == 0)
                break;
            totalFlow += flow;
        }
    }

    cout << totalFlow;

    return 0;
}


