#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
int main(void) {
    FAST
    int T;
    cin >> T;
    int partitionMincost[41];
    for (int i = 0; i <= 40; ++i) {
        partitionMincost[i] = i;
    }
    partitionMincost[1] = 0;
    while(T--){
        int n, k;
        cin >> n >> k;
        int partitionCount = 1;
        for (int i = n; i>=0; --i) {
            if(partitionMincost[i]<=k){
                partitionCount = i;
                break;
            }
        }

//        cout<<partitionCount<<endl;
        int arr[n];
        int cnt = 1;
        for (int i = 0; i < n / partitionCount; ++i) {
            int idxStart = i*partitionCount;
            int idxEnd = (i+1)*(partitionCount)-1;
            int idxMid = (idxStart+idxEnd)/2;

            for (int j = idxMid; j >=idxStart; --j) {
                arr[j] = cnt++;
            }
            for (int j = idxEnd; j >idxMid; --j) {
                arr[j] = cnt++;
            }


        }
        int idxStart = (n/partitionCount)*partitionCount;
        int idxEnd = n-1;
        int idxMid = (idxStart+idxEnd)/2;

        for (int j = idxMid; j >=idxStart; --j) {
            arr[j] = cnt++;
        }
        for (int j = idxEnd; j >idxMid; --j) {
            arr[j] = cnt++;
        }
        for (int i = 0; i < n; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<((n+partitionCount-1)/partitionCount)<<endl;
        for (int i = 1; i <= n/partitionCount; ++i) {
            for (int j = 0; j < partitionCount; ++j) {
                cout<<i<<" ";
            }
        }
        for (int i = n/partitionCount*partitionCount; i < n; ++i) {
            cout<<n/partitionCount+1<<" ";
        }
        cout<<endl;

    }
}
