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
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> lis;
    lis.push_back(arr[0]);
    for (int i = 1; i < n; ++i) {
        if(arr[i]>lis[lis.size()-1]){
            lis.push_back(arr[i]);
        }
        else{
            *upper_bound(lis.begin(), lis.end(),arr[i]) = arr[i];
        }

    }

    cout<<n-lis.size()<<endl;
}

