#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
bool chk[20];
int n;
int arr[20][20];
int mnm = 1e9;

int teamDiff(){
    int teamAct = 0;
    int teamDeAct = 0;
//    for (int i = 0; i < n; ++i) {
//        cout<<chk[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 0; i < n; ++i) {
        if(chk[i]){
            for (int j = i+1; j <n; ++j) {
                if(chk[j]){
                    teamAct+=arr[i][j]+arr[j][i];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!chk[i]){
            for (int j = i+1; j <n; ++j) {
                if(!chk[j]){
                    teamDeAct+=arr[i][j]+arr[j][i];
                }
            }
        }
    }
//    cout<<teamAct<<"  "<<teamDeAct<<endl;
    return abs(teamAct-teamDeAct);
}

void solve(int idx, int cnt){
//    cout<<idx<<" "<<cnt<<endl;
    if(cnt==n/2){
        mnm = min(mnm, teamDiff());
        return;
    }
    if(idx==n)return;
    chk[idx] = true;
    solve(idx+1, cnt+1);
    chk[idx] = false;
    solve(idx+1, cnt);
}

int main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    solve(0,0);
    cout<<mnm<<endl;
}
