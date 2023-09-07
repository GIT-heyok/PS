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
    int n, l;
    cin >> n >> l;
    vector<int> apples(n);

    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
    }
    sort(apples.begin(), apples.end());
    for (int i = 0; i < n; i++)
    {
        if(apples[i]>l)break;
        l++;
    }
    cout<<l<<endl;
    
    
}