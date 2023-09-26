#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
// Be careful of under flow!

int main() {    
    FAST
    int n, m;
    cin >> n >> m;
    ll dist[n+1];
    int graph[n+1][n+1];
    for (int i = 0; i < n+1; i++)
    {
        dist[i] = 1<<29;
        for (int j = 0; j < n+1; j++)
        {
            graph[i][j] = 1<<29;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    bool chk = false;
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            for (int k = 1; k < n+1; k++){
                if(dist[k]>dist[j]+graph[j][k]&&dist[j]<(1<<29)){

                    if(i==n-1){
                        chk = true;
                    }
                    dist[k] = dist[j]+graph[j][k];
                }
            }
        }
    }

    if(chk){
        cout<<-1<<endl;
    }
    else{
        for (int i = 2; i <= n; i++)
        {
            if(dist[i]<(1<<29))
            cout<<dist[i]<<endl;
            else cout<<-1<<endl;
        }
        
    }
    

    

    
}