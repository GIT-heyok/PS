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
vector<int> graph[100];
bool chk[1001];
int d[1001];

bool dfs(int here){
   if(here==1)return false;
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

bool isPrime(int n){
   if(n==1)return false;
   if(n==2)return true;
   for (int i = 2; i*i <= n; i++)
   {
      if(n%i==0)return false;  
   }
   return true;
}
int main() {    
   FAST
   int k;
   cin >> k;
  
   
   vector<int> odds, evens;
   odds.push_back(0);
   evens.push_back(0);
   bool isOddFirst;
   for (int i = 0; i < k; i++)
   {
      int temp;
      cin >> temp;
      if(temp%2==0){
         if(i==0)isOddFirst =false;
         evens.push_back(temp);
      }
      else{
         if(i==0)isOddFirst =true;
         odds.push_back(temp);
      }
   }
   if(evens.size()==1||odds.size()==1){
      cout<<-1<<endl;
      return 0;
   }
      if(odds.size()!=evens.size()){
         cout<<-1<<endl;
         return 0;
      }
      if(isOddFirst){
         n = odds.size()-1;
         m = evens.size()-1;
         for (int i = 1; i <= n; i++)
         {
            for (int j = 1; j <= m; j++)
            {
               if(isPrime(odds[i]+evens[j]))graph[i].push_back(j);
            }
         }
         
      }
      else{
         n = evens.size()-1;
         m = odds.size()-1;
         for (int i = 1; i <= n; i++)
         {
            for (int j = 1; j <= m; j++)
            {
               if(isPrime(evens[i]+odds[j]))graph[i].push_back(j);
            }
         }
      }
      /*
   for (int i = 1; i <=n ; i++)
   {
      for (int j = 0; j < graph[i].size(); j++)
      {
         cout<<graph[i][j]<<" ";
      }
      cout<<endl;
      
   }
   
   */
   vector<int> ans;
   for (int i = 1; i <= n; i++)
   {
      memset(d, 0, sizeof(d));
      if(isOddFirst){
         if(!isPrime(odds[1]+evens[i]))continue;
      }
      else{
         if(!isPrime(evens[1]+odds[i]))continue;
      }
      d[i] = 1;
      int cnt = 1;
      for (int j = 2; j <= n; j++)
      {
         memset(chk, 0, sizeof(chk));
         if(dfs(j))cnt++;
      }
      /*
      for (int j = 1; j <= n; j++)
      {
         cout<<d[j]<<" ";  
      }
      cout<<endl;
      */
      if(cnt==n){
         if(isOddFirst){
            ans.push_back(evens[i]);
         }
         else{
            ans.push_back(odds[i]);
         }
      }
   }
   if(ans.empty()){
      cout<<-1<<endl;
   }
   else{
      sort(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++)
      {
         cout<<ans[i]<<" ";
      }
      cout<<endl;
      
   }
   
   
   
   

}