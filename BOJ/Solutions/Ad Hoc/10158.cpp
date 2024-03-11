#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main(){
    FAST
    long long w, h, p, q, t;
    cin >> w >> h >> p >> q >> t;
    p+=t;
    q+=t;
    p%=(w*2);
    q%=(h*2);
    p = w-abs(w-p);
    q = h-abs(h-q);
    cout<<p<<" "<<q<<endl;
}
