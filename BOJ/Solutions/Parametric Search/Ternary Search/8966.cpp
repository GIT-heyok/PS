#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
ll arr[100000];

ll tri(){
    ll l=0, r = 1e10;
    ll ans=1e18;
    while(r-l>3){
        ll lq = (2*l+r)/3;
        ll uq = (l+2*r)/3;
        
        ll lqVal = 0,uqVal = 0;
        for (int i = 0; i < n; i++)
        {
            lqVal+=abs(lq*i-arr[i]);
            uqVal+=abs(uq*i-arr[i]);
        }
        if(lqVal<=uqVal){
            ans = min(ans, lqVal);
            r = uq-1;
        }
        else{
            ans = min(ans, uqVal);
            l = lq+1;
        }
        
       //cout<<l <<" "<<lqVal<<" "<<r<<" "<<uqVal<<endl;
    }
    for (ll i = l; i <= r; i++)
    {
        ll val1 = 0;
        for (int j = 0; j < n; j++)
        {
            val1+=abs(i*j-arr[j]);
        }
        ans = min(ans, val1);
    }
    
    return ans;
}

int main() {    
    FAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<tri()<<endl;
     
}