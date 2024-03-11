#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

int main(void) {
    FAST
    int n;
    cin >> n;
    int arr[n], left[n], right[n], lmx[n], rmx[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        left[i] = arr[i]+i;
        right[i] = arr[i]+n-i-1;
    }
    int lm = 0, rm = 0;
    lmx[n-1] = arr[n-1];
    rmx[0] = arr[0];
    for (int i = 0; i < n; ++i) {
        lm = max(lm, left[n-i-1]);
        lmx[n-i-1] = lm;
        rm = max(rm, right[i]);
        rmx[i] = rm;
    }
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        int temp = 0;
        if(i>0){
            temp = max(rmx[i-1], temp);
        }
        if(i<n-1){
            temp = max(lmx[i+1], temp);
        }
        ans = min(ans, max(temp, arr[i]));
    }
    cout<<ans<<endl;
}