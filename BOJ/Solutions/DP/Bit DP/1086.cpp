#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int n;
ll k;
ll fact = 1;
ll arr[15];
int len[15];
ll memo[1<<15][100];
ll modTen[51];
ll dfs(int cur, int bit){
    if(bit==(1<<n)-1){
        return cur==0;
    }
    if(memo[bit][cur]!=-1)return memo[bit][cur];
    ll& temp = memo[bit][cur];
    temp = 0;
    for (int i = 0; i < n; ++i) {
        if(bit&(1<<i))
            continue;
        int nextBit = bit|(1<<i);
        int nextVal = (cur*(modTen[len[i]])+arr[i])%k;
        temp += dfs(nextVal, nextBit);
    }
    //cout<<cur<<" "<<bit<<" "<<temp<<endl;
    return temp;

}
int main() {
    FAST
    cin >> n;
    string arr2[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }
    cin >> k;
    modTen[0] = 1%k;
    for (int i = 0; i < 50; ++i) {
        modTen[i+1] = (modTen[i]*10)%k;
    }
    for (int i = 0; i < n; ++i) {
        string s = arr2[i];
        len[i] = s.length();
        int temp = 0;
        for (int j = 0; j < s.length(); ++j) {
            temp *= 10;
            temp += s[j] - '0';
            temp %= k;
        }
        arr[i]= temp;
    }

    for (int i = 1; i <= n; ++i) {
        fact*=i;
    }
    fill(&memo[0][0], &memo[(1<<15)-1][100],-1);
    //memo[0][0]=1;
    ll ans = dfs(0,0);
    if(ans==0)cout<<"0/1"<<endl;
    else
    cout<<ans/gcd(fact,ans)<<"/"<<fact/gcd(fact,ans)<<endl;


}
