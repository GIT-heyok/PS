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
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n];
        bool chk = true;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        bool breakable = true;
        for (int i = 0; i < n-1; ++i) {
            if(breakable){
                if(arr[i]/10>arr[i]%10){
                    breakable = false;
                    if(arr[i]>arr[i+1])
                        chk = false;
                }
                else if(arr[i]%10>arr[i+1]){
                    chk = false;
                }
                else if(arr[i+1]>=10&&arr[i]%10>arr[i+1]/10){
                    breakable=false;
                }
            }
            else{
                if(arr[i]>arr[i+1])chk = false;
            }
        }
        if(chk)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
