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
      int next = graph[here][i];
      if(!chk[next]){
         chk[next] = true;
         if(d[next]==0||dfs(d[next])){
            d[next]=  here;
            return true;
         }
      }
   }
   return false;
   
}
/* jobs will be matching people, and */
int main() {    
   FAST
   cin >> n >> m;
   for (int i = 1; i <= n; i++)
   {
      int temp = 0;
      cin >> temp;
      for (int j = 0; j < temp; j++)
      {
         int x;
         cin >> x;
         graph[i].push_back(x);
      }
   }
   int cnt = 0;
   for(int j=0; j<2; j++)
   for (int i = 1; i <= n; i++)
   {
      memset(chk, 0, sizeof(chk));
      if(dfs(i))cnt++;
   }
   cout<<cnt<<endl;
   

   
}