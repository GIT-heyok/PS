#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main() {    
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        int dist[n+1][m+1]; //how much it takes from 1 -> k where x money is used
        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < m+1; j++)
            {
                dist[i][j] = 1<<29;
            }
        }
        
        for (int i = 0; i < m+1; i++)
        {
            dist[1][i] = 0;
        }
        
        vector<pair<int, pair<int, int>>> vec[n+1];
        for (int i = 0; i < k; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            pair<int,int> p = {c,d};
            pair<int, pair<int,int>> pp = {v,p};
            vec[u].push_back(pp);
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, 1});
        while(!pq.empty()){
            int cur = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();
            if(dist[cur][m]<cost) continue;

            for (int i = 0; i < vec[cur].size(); i++)
            {
                int nxtNode = vec[cur][i].first;
                int nxtCost = vec[cur][i].second.first;
                int nxtDist = vec[cur][i].second.second;
                int prevMnm = 1<<29;
                bool chk = false;
                for (int j = 0; j+nxtCost <= m; j++)
                {
                    dist[nxtNode][j+nxtCost] = min(dist[nxtNode][j+nxtCost], dist[cur][j]+nxtDist);
                    if(prevMnm>dist[nxtNode][j+nxtCost]){
                        prevMnm =dist[nxtNode][j+nxtCost];
                        chk=true;
                    }

                }

                if(chk){
                    pq.push({-prevMnm, nxtNode});
                }

            }
        }
/*
        for (int i = 0; i < n+1; i++)
        {
        for (int j = 0; j < m+1; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
        
        }
  */      

 if(dist[n][m]>=(1<<29))cout<<"Poor KCM"<<endl;
 else  cout<<dist[n][m]<<endl;

    }
}
