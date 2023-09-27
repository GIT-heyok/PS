#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int memo[1001];
bool dp(int n){
    if(memo[n]!=-1)return memo[n];
    int sum = 0;
    for (int i = 0; i <= (n-2)/2; i++)
    {
        cout<<i<<" "<<n-2-i<<endl;
        sum += dp(i)^dp(n-2-i);
    }
    return memo[n] = sum%2;
    
}
int main() {    
    FAST
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    for (int i = 3; i <= 1000; i++)
    {
        memo[i] = -1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<i<<" : "<<dp(i)<<endl;
    }

       
}
