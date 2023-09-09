#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 1000;
const int INF = 987654321;

int main() {    
    FAST
    int n,s=0, o=1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s^=t;
        o &= (t==1);
    }
    bool cubelover;
    if(o)
        cubelover = n%2;
    else   
        cubelover = s==0;
    
    cout<<(cubelover?"cubelover":"koosaga")<<endl;
    
}