#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int n;
int arr[11];
int oper[4];
int operArr[10];
int mnm = 1e9;
int mxm = -1e9;
void calculate(){
    int cur = arr[0];
//    for (int i = 0; i < n-1; ++i) {
//        cout<<operArr[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 0; i < n-1; ++i) {
        if(operArr[i]==0){
            cur+=arr[i+1];
        }
        else if(operArr[i]==1){
            cur-=arr[i+1];
        }
        else if(operArr[i]==2){
            cur*=arr[i+1];
        }
        else{
            cur/=arr[i+1];
        }
    }
    mnm = min(cur,mnm);
    mxm = max(cur,mxm);
}
void solve(int idx){
    if(idx==n-1){
        calculate();
        return;
    }
    if(oper[0]>0){
        operArr[idx] = 0;
        oper[0]--;
        solve(idx+1);
        oper[0]++;
    }
    if(oper[1]>0){
        operArr[idx] = 1;
        oper[1]--;
        solve(idx+1);
        oper[1]++;
    }
    if(oper[2]>0){
        operArr[idx] = 2;
        oper[2]--;
        solve(idx+1);
        oper[2]++;
    }
    if(oper[3]>0){
        operArr[idx] = 3;
        oper[3]--;
        solve(idx+1);
        oper[3]++;
    }
}
int main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >>oper[i];
    }
    solve(0);
    cout<<mxm<<endl;
    cout<<mnm<<endl;
}
