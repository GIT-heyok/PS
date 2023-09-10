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

int main() {    
   FAST
   int n, k;
   cin >> n >> k;
   for (int i = 0; i < n; i++)
   {
      cin >> vec[i+1];
      vec[i+1] += vec[i];
   }
   /*
      relation?: from dp[i] = 
      max(dp[0]+C(2,i),dp[1]+C(3,i),...,dp[i-2],C(i,i))
      until k!
   */

   for (int i = 1; i <= n; i++)
   {
      for (int j = i-1; j >= 0&&i-j>=k; j--)
      {
        // cout<<i-j<<endl;  
         memo[i] = max(memo[j]+cost(j+1,i), memo[i]); 
      }
      
      cout<<memo[i]<<endl;
   }

   
   cout<<memo[n]<<endl;   

   

}