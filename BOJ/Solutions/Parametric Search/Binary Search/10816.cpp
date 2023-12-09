#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int main() {
    FAST
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        cout<<upper_bound(arr.begin(), arr.end(), temp)- lower_bound(arr.begin(), arr.end(), temp)<<" ";
    }
    cout<<endl;
}

