#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
//큰거 붙여놓기

int main(){
    FAST
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    deque<int> dq;
    dq.push_back(arr[n-1]);
    for (int i = n-2; i>=0; i--) {
        if(dq.front()>dq.back()){
            dq.push_front(arr[i]);
        }
        else{
            dq.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = dq.front();
        dq.pop_front();
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=arr[i]*arr[(i+1)%n];
    }
    cout<<sum<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
