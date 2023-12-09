#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int n;
int arr[10][10];
bool chk1[19];
bool chk2[19];

int mxm;
int cur;
//hint: black and white

void dfs(int r, int c){
//    cout<<r<<" "<<c<<endl;
    if(r==n){
        return;
    }
    int chk1Idx = c-r+n-1;
    int chk2Idx = r+c;
    int nxtc = c+2;
    int nxtr = r;

    if(nxtc>=n){
        nxtc = 0;
        nxtr = r+1;
    }

    if((nxtc+nxtr)%2!=(r+c)%2){
        nxtc++;
    }
    if(arr[r][c]&&!chk1[chk1Idx]&&!chk2[chk2Idx]){
        chk1[chk1Idx] = true;
        chk2[chk2Idx] = true;
        cur++;
        mxm = max(mxm, cur);
        dfs(nxtr, nxtc);
        cur--;
        chk1[chk1Idx] = false;
        chk2[chk2Idx] = false;
    }
    dfs(nxtr, nxtc);
}

int main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(0,0);
    int a = mxm;
    mxm = 0;
    cur = 0;
    dfs(0,1);
    int b = mxm;
    cout<<a+b<<endl;
}
