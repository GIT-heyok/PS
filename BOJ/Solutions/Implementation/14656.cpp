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
   int n;
   cin >> n;
   int cnt = 0;
   for (int i = 1; i <= n; i++)
   {
      int temp;
      cin >> temp;
      if(temp!=i)cnt++;
   }
   cout<<cnt<<endl;
   
}