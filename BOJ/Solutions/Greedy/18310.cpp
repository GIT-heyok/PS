#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {    
    FAST
    int n;
    cin >> n;
    vector<ll> vec(n);
    ll curSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        curSum+=vec[i]-vec[0];
    }
    int idx = vec[0];
    ll mnm = curSum;
    for (int i = 1; i < n; i++)
    {
        ll diff = vec[i]-vec[i-1];
        curSum -= diff*(n-2*i);
        if(curSum<mnm){
            mnm = min(curSum,mnm);
            idx = vec[i];
        }
    }
    cout<<idx<<endl;
    /*
        idx: houses on the left. difference
    */
    
}