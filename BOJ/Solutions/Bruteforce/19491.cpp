#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

long long getSum(long long a){
long long temp = 0;
while(a!=0){
    temp += (a%10)*(a%10);
    a/=10;
}
return temp;
    6cin >> vecB[i].second >> vecA[i].first; // A: second element, B: first element
}

int main(void) {
    FAST
    ll k, a, b;
    cin >> k >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 1458; ++i) {
       if((long long)1e18/k<i)break;
        //i: f(n)
        if(i==getSum(k*i))
            if(k*i>=a&&k*i<=b)
                ans++;
    }
    cout<<ans<<endl;

}