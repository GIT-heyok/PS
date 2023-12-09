#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
int main() {
    FAST
    int n;
    cin >> n;
    while(n!=0){
        int cnt = 0;
        for (int i = 1; i*i <= n; ++i) {
            if(i*i==n){
                cnt++;
            }
            for (int j = i; i*i+j*j <= n; ++j) {
                if(i*i+j*j==n){
                    cnt++;
                }
                for (int k = j; i*i+j*j+k*k <= n; ++k) {
                    if(i*i+j*j+k*k==n){
                        cnt++;
                    }
                    for (int l = k; i*i+j*j+k*k+l*l <= n; ++l) {
                        if(i*i+j*j+k*k+l*l==n){
                            cnt++;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
        cin >> n;
    }
}
