#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int INF = 987654321;


int n,m;
vector<int> graph[1001];
bool chk[1001];
int d[1001];
int cnt = 0;
int ans = 0;

bool dfs(int here){
   for (int i = 0; i < graph[here].size(); i++)
   {
      int nxt = graph[here][i];
      if(!chk[nxt]){
         chk[nxt] = true;
         if(!d[nxt]||dfs(d[nxt])){
            d[nxt] = here;
            return true;
         }
      }
   }
   
   return false;
}

int main() {    
   FAST
   cin >> n >> m;
   vector<int> a1(n), a2(m);
   for (int i = 0; i < n; i++)
   {
      cin >> a1[i];
   }
   for (int i = 0; i < m; i++)
   {
      cin >> a2[i];
   }

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if((a1[i]<=a2[j]*2&&3*a1[i]>=4*a2[j])||(a1[i]<=a2[j]&&5*a1[i]>=4*a2[j])){
            graph[i+1].push_back(j+1);
         }
      }
      
   }
   
   int cnt = 0;
   for (int i = 1; i <= n; i++)
   {
      memset(chk, 0, sizeof(chk));
      if(dfs(i))cnt++;
   }
   
   cout<<cnt<<endl;
   

   
}