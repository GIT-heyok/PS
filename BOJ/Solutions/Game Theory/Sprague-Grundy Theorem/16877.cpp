#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main()
{
    FAST
    int fibonacci[35];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 0; i < 35 - 2; ++i) {
        fibonacci[i+2] = fibonacci[i]+fibonacci[i+1];
    }

    int memo[3000001];
    memo[0] = 0;
    memo[1] = 1;
    int mxm = 0;
    for (int i = 2; i < 3000001; ++i) {
        bool chk[32];
        memset(chk, 1, sizeof(chk));
        for (int j = 0; j < 35; ++j) {
            if(i-fibonacci[j]<0)break;
            chk[memo[i-fibonacci[j]]] = false;
        }
        for (int j = 0; j < 32; ++j) {
            if(chk[j]){memo[i]= j;
            break;}
        }
    }
    int n;
    cin >> n;
    int arr[n];
    int grundy = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        grundy^=memo[temp];
    }
    if(grundy){
        cout<<"koosaga"<<endl;
    }
    else cout<<"cubelover"<<endl;
}


