#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
const int MAX = 1000;
const int INF = 987654321;

ll arr[33];
ll mxm[34];
map<ll, ll> m;
int dp(ll r){
    if(r==0)return 0;
    if(r==1)return 1;
    if(m[r]){
        return m[r];
    }
    int ans = 0;
    int divider = 32;
    for (int i = 32; i >0; i--)
    {
        if(r>=arr[i]){
            divider = i;
            break;
        }
    }
    ans = max(ans, dp(arr[divider]-1));
    ans = max(ans, divider+dp(r-arr[divider]));
    m[r] = ans;
    return ans;
    
}

int divideAndConquer(ll l, ll r){
   
   //cout<<l<<" "<<r<<endl;
    int ans = 0;
    if(r-l<=1){
        int cnt = 0;
        for (int j = 32; j >= 1; j--)
        {
            while(r>=arr[j]){
                cnt+=j;
                r-=arr[j];
            }
        }
        ans = max(ans, cnt);   
        cnt = 0;
        for (int j = 32; j >= 1; j--)
        {
            while(l>=arr[j]){
                cnt+=j;
                l-=arr[j];
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
    if(l==0||l==1){
        return dp(r);
    }
    
    int divider = 32;
    for (int i = 32; i > 0; i--)
    {
        if(arr[i]<=r){
            divider = i;
            break;
        }
    }
    if(arr[divider]<=l)
        ans = max(ans, divider+divideAndConquer(l-arr[divider],r-arr[divider]));
    else{
        ans = max(ans, divideAndConquer(l,arr[divider]-1));
        ans = max(ans, divider+divideAndConquer(0,r-arr[divider]));
    }
    return ans;
}
int main() {    
    FAST
    /*jumps are like: 1 2 4 8 16 ... -> greedy-able?
    2^n-1 
    */

        ll temp = 1;
        mxm[1] = 1;
   for (int i = 1; i < 33; i++)
   {
        mxm[i+1] = mxm[i]+i;
        arr[i] = temp;
        //cout<<i<<" : "<<temp<<endl;
        temp*=2;
        temp++;
   }
/*
   int mxm = 0;
   for (int i = 1; i < 2000000; i++)
   {
    int tempi=i, cnt = 0;
        for (int j = 20; j >= 1; j--)
        {
            while(tempi>=(1<<j)-1){
                cnt+=j;
                tempi-=(1<<j)-1;
        }
        }
        mxm = max(mxm, cnt);
        if(mxm!=dp(i)){
            cout<<"on "<<i<<" expected "<<mxm<<" but "<<dp(i)<<endl;
        }

   }
   */

   
int T;
cin >> T;
while(T--){
    int a, b;
    cin >> a >> b;
    cout<<divideAndConquer(a,b)<<endl;
}


}