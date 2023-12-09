#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

int main() {
    FAST
    int T;
    cin >> T;
    while(T--){
       int n, m;
       cin >> n >> m;
       bool isPlaceable[n][m];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                isPlaceable[i][j] = s[j] == '.';
            }
        }
        int memo[n+1][(1<<m)];

        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < (1<<m); ++j) {
                memo[i][j] = 0;
            }
        }

        for (int row = 0; row < n; ++row) {

            for (int currentBit = 0; currentBit < (1<<m); ++currentBit) {
                bool currentBitChk = true;
                int cnt = 0;
                for (int bit = 0; bit < m; ++bit) {
                    if(currentBit&(1<<bit)){
                        cnt++;
                        if(isPlaceable[row][bit]){

                            if(bit!=0){
                                if(currentBit&(1<<(bit-1))){
                                    currentBitChk = false;
                                }
                            }

                            if(bit!=m-1){
                                if(currentBit&(1<<(bit+1))){
                                    currentBitChk = false;
                                }
                            }
                        }
                        else{
                            currentBitChk = false;
                        }
                    }
                }

                if(currentBitChk){
                    for (int previousBit = 0; previousBit < (1 << m); ++previousBit) {
                        bool previousBitChk = true;
                        for (int bit = 0; bit < m; ++bit) {
                            if(currentBit&(1<<bit)){
                                if(bit!=0){
                                    if(previousBit&(1<<(bit-1))){
                                        previousBitChk = false;
                                    }
                                }

                                if(bit!=m-1){
                                    if(previousBit&(1<<(bit+1))){
                                        previousBitChk = false;
                                    }
                                }
                            }
                        }
                        if(previousBitChk){
                            memo[row+1][currentBit] = max(memo[row+1][currentBit], memo[row][previousBit]+cnt);
                        }
                    }
                }
            }
        }


        int ans = 0;

        for (int j = 0; j < (1 << m); ++j) {
            ans = max(ans, memo[n][j]);
        }
        cout<<ans<<endl;
    }


}
