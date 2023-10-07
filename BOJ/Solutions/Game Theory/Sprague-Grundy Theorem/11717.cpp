#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

char arr[20][20];
int grundy[20][20][20][20];

int dp(int r1, int c1, int r2, int c2){
    if(r2-r1<0||c2-c1<0)return 0;
    int& cur = grundy[r1][c1][r2][c2];
    if(cur!=-1)return cur;

    bool chkMex[20];
    for (int i = 0; i < 20; ++i) {
        chkMex[i] = false;
    }

    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            if(arr[i][j]=='X')continue;
            int curGrundy = 0;
            curGrundy ^= dp(r1, c1,i-1,j-1);
            curGrundy ^= dp(r1, j+1,i-1,c2);
            curGrundy ^= dp(i+1, c1,r2,j-1);
            curGrundy ^= dp(i+1, j+1,r2,c2);
            chkMex[curGrundy] = true;
        }
    }
    int temp = 0;
    for (int i = 0; i < 20; ++i) {
        if(!chkMex[i]){
            temp = i;

            break;
        }
    }

//    cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<temp<<endl;
        return cur = temp;

}
int main() {
    FAST
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            arr[i][j] = s[j];
        }
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 20; ++k) {
                for (int v = 0; v < 20; ++v) {
            grundy[i][j][k][v] = -1;
        }}}
    }
    if(dp(0,0,h-1,w-1))cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}


