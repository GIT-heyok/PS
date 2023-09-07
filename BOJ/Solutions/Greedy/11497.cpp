#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

/*
think of diagonally cut cylinder as a reference:
this way, only first two and last two indices meet
each other. With the former two as an exception,
every other numbers meet with a 2-index diffence.
*/

int main() {    
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> logs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> logs[i];
        }
        sort(logs.begin(), logs.end());

        int mxdiff = max(logs[1]-logs[0],logs[n-1]-logs[i-2]);
        for (int i = 2; i < n; i++)
        {
            mxdiff = max(mxdiff, logs[i]-logs[i-2]);
        }
        cout<<mxdiff<<endl;
        
    }
}