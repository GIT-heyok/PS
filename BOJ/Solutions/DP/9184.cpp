#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll memo[21][21][21];

ll dp(int a, int b, int c){
    if(a<=0||b<=0||c<=0)return 1;
    else if(a>20||b>20||c>20)return dp(20,20,20);
    if(memo[a][b][c]!=-1)return memo[a][b][c];
    ll& ret = memo[a][b][c];
    ret = 0;
    if(a<b&&b<c){
        ret = dp(a,b,c-1)+dp(a,b-1,c-1)-dp(a,b-1,c);
    }
    else{
        ret = dp(a-1,b,c)+dp(a-1,b-1,c)+dp(a-1,b,c-1)-dp(a-1,b-1,c-1);
    }
    return ret;
}
int main() {
    FAST
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            for (int k = 0; k < 21; ++k) {
                memo[i][j][k]= -1;
            }
        }
    }

    while(true){
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dp(a,b,c)<<endl;
        cin >> a >> b >> c;
    }
}

