#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int INF = 987654321;

int main() {    
    FAST
 int n;
   cin >> n;
   deque<ll> a(n);
   deque<ll> ans;
   for (int i = 0; i < n; i++)
   {
        cin >> a[i];
   }
   
   sort(a.begin(), a.end());
   ans.push_back(a.back());
   a.pop_back();
   ll sum = 0;
   while (a.size()>0) {
      int LL = abs(a.front() - ans.front());
      int LR = abs(a.front() - ans.back());
      int RL = abs(a.back() - ans.front());
      int RR = abs(a.back() - ans.back());
      if (LL >= LR && LL >= RL && LL >= RR) {
         ans.push_front(a.front());
         a.pop_front();
      } else if (LR >= LL && LR >= RL && LR >= RR) {
         ans.push_back(a.front());
         a.pop_front();
      } else if (RL >= LL && RL >= LR && RL >= RR) {
         ans.push_front(a.back());
         a.pop_back();
      } else {
         ans.push_back(a.back());
         a.pop_back();
      }
   }
   for (int i = 0; i < n - 1; i++) sum += abs(ans[i] - ans[i + 1]);
   cout << sum;
}
