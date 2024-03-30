#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int dict[200001][26];
int main()
{
    FAST
    string h, n;
    cin >> h >> n;
    int arr[n.length()];
    int hash = 0;
    for (int i = 0; i < n.length(); ++i) {
        hash *= h.size();
        for (int j = 0; j < h.length(); ++j) {
            if(n[i] == h[j]){
                hash+=j+1;
            }
        }
        hash%=900528;
    }
    cout<<hash<<endl;
}
