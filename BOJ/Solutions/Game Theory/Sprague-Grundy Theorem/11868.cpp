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
    int n;
    int s = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s^=t;
    }
    bool chk = s!=0;
    if(chk)cout<<"koosaga"<<endl;
    else cout<<"cubelover"<<endl;

    
}