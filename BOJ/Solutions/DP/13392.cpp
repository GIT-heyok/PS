#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF = 987654321;


vector<ll> vec(100001);
vector<ll> memo(100001);
ll cost(int l, int r){
   if(l>r)return 0;
   return vec[r]-vec[l-1];
}

int requiredLeftTurns(int from, int to){
   return (to+10-from)%10;
}
int requiredRightTurns(int from, int to){
   return (from+10-to)%10;
}

int main() {    
   FAST
   int n;
   cin >> n;
   string s;
   cin >> s;
   int arr1[n], arr2[n];
   for (int i = 0; i < n; i++)
   {
      arr1[i] = s[i]-'0';
   }
   cin >> s;
   
   for (int i = 0; i < n; i++)
   {
      arr2[i] = s[i]-'0';
   }

   int dp[n][10]; 
   fill(&dp[0][0], &dp[n-1][10], 1<<29);
   //right turn = 10-left turn
   int temp = requiredRightTurns(arr1[0], arr2[0]);
   dp[0][0] = temp;
   for (int i = 0; i < 10; i++)
   {
      dp[0][i] = min(dp[0][i],i+requiredRightTurns((arr1[0]+i)%10,arr2[0]));
      //cout<<dp[0][i]<<" ";
   }
  // cout<<endl;

   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j < 10; j++)
      {
         dp[i][j] = dp[i-1][j]+requiredRightTurns((arr1[i]+j)%10,arr2[i]);
      }  
      for (int j = 0; j < 10; j++)
      {
      
         for (int rotation = 0; rotation < 10; rotation++)
         {
            dp[i][(j+rotation)%10] = min(dp[i][(j+rotation)%10],dp[i-1][j]+rotation+requiredRightTurns((arr1[i]+j+rotation)%10,arr2[i]));
         }
         //cout<<dp[i][j]<<" ";
      }
     // cout<<endl;
   }
   int ans = 1<<29;

   for (int i = 0; i < 10; i++)
   {
      ans = min(ans, dp[n-1][i]);
   }
   cout<<ans<<endl;
   
   
   
   

}