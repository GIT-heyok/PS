#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main(){
    FAST
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> ans;
    int m;
    cin >> m;
    for (int i = 0; i < n; ++i) {
        int mxm = 0;
        int idx = -1;
        int comparedprev = 0;
        int compared = 0;
        for (int j = 0; j < n; ++j) {
            if(arr[j]!=0&&m>=comparedprev){
                if(mxm < arr[j]){
                    compared = comparedprev;
                    mxm = arr[j];
                    idx = j;
                }
                comparedprev++;
            }
        }
        if(idx==-1)
            break;
        else{
            ans.push_back(mxm);
            arr[idx] = 0;
            m-=compared;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<" ";
    }
    for (int i = 0; i < n; ++i) {
        if(arr[i]>0){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}
