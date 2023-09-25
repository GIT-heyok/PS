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
    int v, e;
    cin >> v >> e;
    int arr[v+1][v+1];
    int dist[v+1][v+1];
    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0; j < v+1; j++)
        {
            arr[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        arr[a][b] = w;
    }
    for (int i = 1; i <= v ; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if(i==j)dist[i][j]=0;
            else if(arr[i][j])dist[i][j] = arr[i][j];
            else dist[i][j] = 1<<29;
        }
        
    }
    for (int k = 1; k <=v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
            
        }
        
    }
    int ans  = 1<<29;
    for (int i = 1; i <= v; i++)
    {
      for (int j = i+1; j < v+1; j++)
      {
         ans = min(ans, dist[i][j]+dist[j][i]);
      }
      
    }
    if(ans>=(1<<29)){
      cout<<-1<<endl;
    }
    else cout<<ans<<endl;
    
    

   
}