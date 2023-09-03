#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main()
{
    FAST
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    
    while(a<b){
        if(b%2==0){
            b/=2;
        }
        else if(b%10==1){
            b/=10;
        }
        else{
            b = 0;
        }
        cnt++;
    }
    if(a==b)cout<<cnt+1<<endl;
    else cout<<-1<<endl;
}